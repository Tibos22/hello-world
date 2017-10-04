#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};
struct node *pnode;

struct node *creat_list(void)
{
	int len, i;
	printf("请输入链表长度：\n");
	scanf("%d", &len);
	struct node *phead = malloc(sizeof(struct node));
	phead->next = NULL;
	struct node *ptail = phead;
	for (i=0; i<len; i++) {
		int val;
		printf("请输入第%d个值\n", i+1);
		scanf("%d", &val);
		struct node *new = malloc(sizeof(struct node));
		new->data = val;
		new->next = NULL;
		ptail->next = new;
		ptail = new;
	}
	return phead;
}

void traverse(struct node *phead)
{
	struct node *node = phead->next;
	printf("-------------------\n");
	while (node != NULL) {
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n-------------------\n");
}

bool isempty(struct node *phead)
{
	if (phead->next == NULL) {
		return true;
	} else {
		return false;
	}
}

int list_len(struct node *phead)
{
	int len = 0;
	struct node *node = phead->next;
	while (node != NULL) {
		len++;
		node = node->next;
	} 
	return len;
}

bool insert_val(struct node *phead, int pos, int val)
{
	int i = 0;
	struct node *node = phead->next;
	while (node!=NULL && i<pos-1) {
		i++;
		node = node->next;
	}
	if (i>pos-1 || node == NULL) {
		printf("插入位置不合法\n");
		return false;
	}
	struct node *new = malloc(sizeof(struct node));
	new->data = val;
	new->next = node->next;
	node->next = new;

	return true;
}

bool delete_val(struct node *phead, int pos, int *val)
{
	int i = 0;
	struct node *node = phead->next;
	while (node!=NULL && i<pos-1) {
		i++;
		node = node->next;
	}
	if (node==NULL || i>pos-1) {
		printf("插入位置不合法\n");
		return false;
	}
	struct node *p = node->next;
	*val = p->data;
	node->next = p->next;
	free(p);
	return true;
}

int main(void)
{
	struct node *phead = creat_list();
	if (isempty(phead)) {
		printf("链表为空\n");
	}
	printf("链表长度为%d\n", list_len(phead));
	traverse(phead);
	insert_val(phead, 1, 7);
	traverse(phead);
	int val;
	delete_val(phead, 1, &val);
	traverse(phead);
	return 0;
}
