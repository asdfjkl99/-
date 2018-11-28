#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int top;
	int max;
	int* stk;
}stack;

int initialize(stack* s, int max)
{
	s->stk = (int *)calloc(max, sizeof(int));

	if (s->stk == NULL)
		return 0;

	s->max = max;
	s->top = -1;

	return 1;
}

int isEmpty(stack* s)
{
	if (s->top == -1)
		return 1;

	return 0;
}

int isFull(stack* s)
{
	if (s->top == s->max - 1)
		return 1;

	return 0;
}

void push(stack* s, int inc)
{
	if (isFull(s))
		return;

	s->top++;
	s->stk[s->top] = inc;
}

int pop(stack* s)
{
	if (isEmpty(s))
		return 0;

	int temp;

	temp = s->stk[s->top];
	s->top--;

	return temp;
}

int peek(stack* s)
{
	if (isEmpty(s))
		return 0;

	int temp;

	temp = s->stk[s->top];

	return temp;
}

int Balance(stack* s, char* input)
{
	int temp = 0;

	if (input == NULL || s == NULL)
		return -1;

	for (int i = 0; i < strlen(input); i++)
	{
		switch (input[i])
		{
		case'(':case')':
			if (peek(s) == 1)
				temp = pop(s);
			else
				push(s, 1);
			break;
		case'{':case'}':
			if (peek(s) == 2)
				temp = pop(s);
			else
				push(s, 2);
			break;
		case'[':case']':
			if (peek(s) == 3)
				temp = pop(s);
			else
				push(s, 3);
			break;
		}
	}

	if (isEmpty(s))
		return 1;
	else
		return 0;
}

void main()
{
	stack s;
	char input[50];
	
	printf("수식을 입력하세요 : \n");
	scanf("%s", input);

	initialize(&s, 50);

	if (Balance(&s, input))
		printf("Yes \n");
	else
		printf("No \n");
}

