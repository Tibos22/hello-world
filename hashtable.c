#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "stdbool.h"

#define M 7

typedef int elem_type;

struct node {
	elem_type data;
	struct node *next;
};

struct hash_node {
	struct node *first;
};

struct hash_node *create_hashtable(int n)
{
	struct hash_node *hashtable = (struct hash_node *)malloc(sizeof(struct hash_node)*n);
	if (!hashtable) {
		printf("hash malloc fail\n");
		exit(-1);
	}
	int i;
	for (i=0; i<n; i++) {
		hashtable[i].first = NULL;
	}
	return hashtable;
}

struct node *search_hashtable(struct hash_node *hashtable, elem_type data)
{
	if (!hashtable) {
		return NULL;
	}	
	struct node *pnode = hashtable[data%M].first;
	while (pnode && pnode->data != data) {
		pnode = pnode->next;
	}
	return pnode;
}

bool insert_hashtable(struct hash_node *hashtable, elem_type data)
{
	if (search_hashtable(hashtable, data)) {
		return false;
	}
	struct node *pnew = (struct node *)malloc(sizeof(struct node));
	pnew->data = data;
	pnew->next = NULL;
	struct node *pnode = hashtable[data%M].first;
	if (!pnode) {
		hashtable[data%M].first = pnew;
	} else {
		while (pnode->next) {
			pnode = pnode->next;
		}
		pnode->next = pnew;
	}
	return true;
}

bool delete_hashtable(struct hash_node *hashtable, elem_type data)
{
	if (!search_hashtable(hashtable, data)) {
		return false;
	}
	struct node *pnode = hashtable[data%M].first;
	if (pnode->data == data) {
		hashtable[data%M].first = pnode->next;
		free(pnode);
	} else {
		while (pnode && pnode->next->data != data) {
			pnode = pnode->next;
		}
		struct node *tmp;
		tmp = pnode->next;
		pnode = pnode->next->next;
		free(tmp);
	}
	return true;
}

void destroy_hashtable(struct hash_node *hashtable)
{
	int i;
	for (i=0; i<M; i++) {
		struct node *pnode = hashtable[i%M].first;
		while (pnode) {
			struct node *tmp = pnode;
			pnode = pnode->next;
			free(tmp);
		}
	}
	free(hashtable);
}

int main(void)
{
	int len = 15;
	struct hash_node *hashtable = create_hashtable(len);
	if (insert_hashtable(hashtable, 1)) {
		printf("insert 1 success\n");
	} else {
		printf("insert 1 fail\n");
	}
	if (insert_hashtable(hashtable, 8)) {
		printf("insert 1 success\n");
	} else {
		printf("insert 1 fail\n");
	}
	if (insert_hashtable(hashtable, 3)) {
		printf("insert 1 success\n");
	} else {
		printf("insert 1 fail\n");
	}
	if (insert_hashtable(hashtable, 10)) {
		printf("insert 1 success\n");
	} else {
		printf("insert 1 fail\n");
	}
	if (insert_hashtable(hashtable, 8)) {
		printf("insert 1 success\n");
	} else {
		printf("insert 1 fail\n");
	}
	struct node *pfind = search_hashtable(hashtable, 10);
	if (pfind) {
		printf("find success\n");
	} else {
		printf("not find\n");
	}
}
