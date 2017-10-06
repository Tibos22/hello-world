#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define LEN 6

struct queue {
	int *pbase;
	int front;
	int rear;
};

void init_queue(struct queue *pq)
{
	pq->pbase = malloc(sizeof(int)*LEN);
	pq->front = 0;
	pq->rear = 0;
}

bool isfull(struct queue *pq)
{
	if ((pq->rear+1)%LEN == pq->front) {
		printf("队列已满\n");
		return true;
	}
	return false;
}

bool isempty(struct queue *pq)
{
	if (pq->rear == pq->front) {
		printf("队列为空\n");
		return true;
	}
	return false;
}

bool insert(struct queue *pq, int val)
{
	if (isfull(pq)) {
		return false;
	}
	pq->pbase[pq->rear] = val;
	pq->rear = (pq->rear+1)%LEN;
	return true;
}

bool out(struct queue *pq, int *val)
{
	if (isempty(pq)) {
		return false;
	}
	*val = pq->pbase[pq->front];
	pq->front = (pq->front+1)%LEN;
	return true;
}

void traverse(struct queue *pq)
{
	int i = pq->front;
	printf("--------------\n");
	while (i != pq->rear) {
		printf("%d", pq->pbase[i]);
		i = (i+1)%LEN;
	}
	printf("\n--------------\n");
}

int main(void)
{
	struct queue q;
	int val;
	init_queue(&q);
	insert(&q, 1);
	insert(&q, 2);
	insert(&q, 3);
	insert(&q, 4);
	insert(&q, 5);
	insert(&q, 6);
	traverse(&q);
	out(&q, &val);
	traverse(&q);
	insert(&q, 6);
	traverse(&q);
	return 0;
}
