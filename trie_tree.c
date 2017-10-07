#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

#define MAX 26

typedef struct node {
	struct node *next[MAX];
	int count;
}trie_node, *trie_tree;

trie_tree creat_trietree(void)
{
	trie_tree tree = (trie_tree)malloc(sizeof(trie_node));
	if (!tree) {
		printf("malloc fail\n");
		exit(-1);
	}
	tree->count = 0;
	int i;
	for (i=0; i<MAX; i++) {
		tree->next[i] = NULL;
	}
	return tree;
}

void insert_trietree(trie_tree des_tree, char *str)
{
	trie_tree tree = des_tree;	
	int len = strlen(str);
	int i;
	for (i=0; i<len; i++) {
		unsigned int id = str[i] - 'a';
		if (id > ('z' - 'a')) {
			return;
		}
		if (!tree->next[id]) {
			tree->next[id] = creat_trietree();
			tree = tree->next[id];	
			tree->count = 1;
		} else {
			tree = tree->next[id];
			tree->count++;
		}
	}
}

int count_trietree(trie_tree des_tree, char *str)
{
	trie_tree tree = des_tree;
	int len = strlen(str);
	int i;
	for (i=0; i<len; i++) {
		int id = str[i] - 'a';
		if (!tree->next[id]) {
			return 0;
		} else {
			tree = tree->next[id];
		}
	}
	return tree->count;
}

void delete_trietree(trie_tree tree)
{
	int i;
	for (i=0; i<MAX; i++) {
		if (tree->next[i]) {
			delete_trietree(tree->next[i]);
		}
	}
	free(tree);
}

int main(char argc, char *argv[])
{
	trie_tree tree;
	tree = creat_trietree();
	int i;
	for (i=1; i<argc; i++) {
		insert_trietree(tree, argv[i]);
	}
	char dst[10];
	printf("输入查找目标(长度10以内):");
	scanf("%s", dst);
	int count;
	count = count_trietree(tree, dst);
	printf("%s's counts:%d\n", dst, count);
	return 0;
}
