#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int top;
	int max;
	char* stk;
}stack;

int initialize(stack* s, int max)
{
	s->stk = (char *)calloc(max, sizeof(char));

	if (s->stk == nullptr)
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

void push(stack* s, char* inc)
{
	if (isFull(s))
		return;
	
	s->top++;
	s->stk[s->top] = *inc;
}

char* pop(stack* s)
{
	if (isEmpty(s))
		return nullptr;

	char* temp;

	*temp = s->stk[s->top];
	s->top--;
	
	return temp;
}

char* peek(stack* s)
{
	if (isEmpty(s))
		return nullptr;

	char* temp;

	*temp = s->stk[s->top];

	return temp;
}