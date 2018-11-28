#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int top;
	int max;
	char* stk;
}stack;

char initialize(stack* s, char max)
{
	s->stk = (char *)calloc(max, sizeof(char));

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

void push(stack* s, char inc)
{
	if (isFull(s))
		return;

	s->top++;
	s->stk[s->top] = inc;
}

char pop(stack* s)
{
	if (isEmpty(s))
		return 0;

	char temp;

	temp = s->stk[s->top];
	s->top--;

	return temp;
}

char peek(stack* s)
{
	if (isEmpty(s))
		return 0;

	char temp;

	temp = s->stk[s->top];

	return temp;
}

void PrintStack(stack* s)
{
	for (int i = 0; i <= s->top; i++)
		printf("%c", s->stk[i]);

	printf("\n");
}

void Reverse_String(stack* s1, stack* s2, char* input)
{
	int i = 0;

	for (i = 0; i < strlen(input); i++)
		push(s1, input[i]);

	for (i = 0; i <= strlen(input); i++)
		push(s2, pop(s1));

	PrintStack(s2);
}

void main()
{
	stack s1, s2;
	char input[50];

	initialize(&s1, 50);
	initialize(&s2, 50);

	printf("문자열을 입력하세요. : \n");
	scanf("%s", input);

	Reverse_String(&s1, &s2, input);
}