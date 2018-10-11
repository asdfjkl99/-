#include <stdio.h>
#include "linear queue.h"

void main()
{
	Queue q;
	QueueInit(&q);

	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	EnQueue(&q, 4);
	EnQueue(&q, 5);
	EnQueue(&q, 6);

	for (int i = 0; i < 3; i++)
		DeQueue(&q);

	printf("%d°³ \n", CountCircularQ(&q));
}