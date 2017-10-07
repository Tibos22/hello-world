#include <stdio.h>
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
	tree->count = 0;
	int i;
	for (i=0; i<MAX; i++) {
		tree->next[i] = NULL;
	}
	return tree;
}


