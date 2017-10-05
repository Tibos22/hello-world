#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

struct stack {
	struct node *top;
	struct node *bottom;
};

void stack_init(struct stack *pstack)
{
	pstack->bottom = malloc(sizeof(struct node));	
	pstack->top = pstack->bottom;
	pstack->top->next = NULL;
}

void traverse(struct stack *pstack)
{
	if (pstack->top == pstack->bottom) {
		printf("空栈\n");
		return;
	}
	struct node *pnode;
	pnode = pstack->top;
	printf("----------------\n");
	while (pnode != pstack->bottom) {
		printf("%d", pnode->data);
		pnode = pnode->next;
	}
	printf("\n----------------\n");
}

void push(struct stack *pstack, int val)
{
	struct node *new = malloc(sizeof(struct node));	
	new->data = val;
	new->next = pstack->top;
	pstack->top = new;
}

void pop(struct stack *pstack, int *val)
{
	if (pstack->top == pstack->bottom) {
		printf("空栈\n");
		return;
	}
	struct node *tmp = pstack->top;
	*val = tmp->data;
	pstack->top = tmp->next;
	free(tmp);
}

void clean(struct stack *pstack)
{
	struct node *tmp;
	while (pstack->top != pstack->bottom) {
		tmp = pstack->top;
		pstack->top = tmp->next;
		free(tmp);
	}
}

void setval(struct stack *pstack)
{
	int len, i;
	printf("请输入栈长度:");
	scanf("%d", &len);
	for (i=0; i<len; i++) {
		int val;
		printf("请输入第%d个值:", i+1);
		scanf("%d", &val);
		push(pstack, val);
	}
}

int main(void)
{
	int val;
	struct stack stack;
	stack_init(&stack);
	setval(&stack);
	traverse(&stack);
	pop(&stack, &val);
	traverse(&stack);
	clean(&stack);
	traverse(&stack);
	return 0;
}
