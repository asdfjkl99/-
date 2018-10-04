#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int max;
	int* que;
	int front;
	int rear;
}IntQueue;

int initializeQ (IntQueue* q, int max)
{
	q->front = -1;
	q->rear = -1;
	q->max = max;
	q->que = (int *)calloc(max, sizeof(int));

	if (q->que == NULL)
		return 0;

	return 1;
}

int isQEmpty(IntQueue* q)
{
	return (q->rear == -1 && q->front == -1) ? 1 : 0;
}

int isQFull(IntQueue* q)
{
	return (q->rear == q->max - 1 && q->rear != -1) ? 1 : 0;
}

int enqueue(IntQueue* q, int x)
{
	if (isQFull(q))
		return 0;

	if (isQEmpty(q))
		q->front++;
		
	q->rear++;
	q->que[q->rear] = x;

	return 1;
}

int dequeue(IntQueue* q, int* temp)
{
	if (isQEmpty(q))
		return 0;

	*temp = q->que[q->front];
	q->front++;

	if (q->front > q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}

	return 1;
}

void printQ(IntQueue* q)
{
	if (isQEmpty(q))
		return;

	for (int i = q->front; i <= q->rear; i++)
		printf("%d ", q->que[i]);

	printf(" \n");
}

int countQ(IntQueue* q)
{
	if (isQEmpty(q))
		return 0;

	return q->rear - q->front + 1;
}

int terminateQ (IntQueue* q)
{
	if (q->que == NULL)
		return 0;

	free(q->que);
	return 1;
}

int main()
{
	IntQueue q;
	int temp;

	initializeQ(&q, 100);
	if (q.que != NULL && q.max != 0)
		printf("Initializing is succeed! :) \nQ size : %d \n", q.max);
	else
		printf("Initializing is failed! :( \n");

	enqueue(&q, 1);

	if (isQEmpty(&q))
		printf("Q is empty! :( \n");
	else
		printf("Q is not empty! :) \n");
	
	if (isQFull(&q))
		printf("Q is full! :( \n");
	else
		printf("Q is not full! :) \n");

	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);

	printQ(&q);

	printf("Counting is succeed! Queue count is %d :) \n", countQ(&q));

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	printf("Counting is succeed! Queue count is %d :) \n", countQ(&q));

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	printf("Counting is succeed! Queue count is %d :) \n", countQ(&q));

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	printf("Counting is succeed! Queue count is %d :) \n", countQ(&q));

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	if (dequeue(&q, &temp))
		printf("Dequeue is succeed! Dequeue value is %d :) \n", temp);
	else
		printf("Dequeue is failed! :( \n");

	printQ(&q);

	return 0;
}