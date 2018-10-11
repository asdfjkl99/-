#pragma once
#include <stdio.h>
#define LEN 6

typedef int Data;

typedef struct arrayqueue
{
	int front;
	int rear;
	Data arr[LEN];
}Queue;

void QueueInit(Queue*pq);
int QIsEmpty(Queue*pq);
int QIsFull(Queue*pq);
void EnQueue(Queue*pq, Data data);
Data DeQueue(Queue*pq);
Data Peek(Queue*pq);
Data CountCircularQ(Queue*pq);

void QueueInit(Queue*pq)
{
	pq->front = -1;
	pq->rear = -1;
	for (int i = 0; i < LEN; i++)
		pq->arr[i] = NULL;
}

int QIsEmpty(Queue*pq)
{
	if (pq->front == -1 && pq->rear == -1)
		return 1;

	return 0;
}

int QIsFull(Queue*pq)
{
	if (pq->front == (pq->rear + 1) % LEN)
		return 1;

	return 0;
}

void EnQueue(Queue*pq, Data data)
{
	if (QIsFull(pq))
	{
		printf("Queue is Full! \n");
		return;
	}

	if (QIsEmpty(pq))
	{
		pq->front = 0;
		pq->rear = 0;
	}

	pq->arr[++pq->rear] = data;

	if (pq->rear >= LEN)
		pq->rear = pq->rear % LEN;

	printf("Enqueue is succeed! \n");
}

Data DeQueue(Queue*pq)
{
	if (QIsEmpty(pq))
		return 0;

	pq->front++;

	if (pq->front >= LEN)
		pq->front = pq->front % LEN;

	int temp = pq->arr[pq->front];
	
	if (pq->front == pq->rear)
	{
		pq->front = -1;
		pq->rear = -1;
	}

	return temp;
}

Data Peek(Queue*pq)
{
	if (QIsEmpty(pq))
		return 0;

	return pq->arr[pq->front++];
}

Data CountCircularQ(Queue*pq)
{
	if (pq->rear > pq->front)
		return pq->rear - pq->front;

	else
		return LEN - ((unsigned)pq->rear - pq->front);
}