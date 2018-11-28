#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack
{
	int top;
	int max;
	char** stk;
}stack;

void initialize(stack* s, char max)
{
	s->stk = (char **)calloc(max, sizeof(char) * max);

	if (s->stk == NULL)
		return;

	s->max = max;
	s->top = -1;
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
	s->stk[s->top] = inc;
}

char* pop(stack* s)
{
	if (isEmpty(s))
		return NULL;

	char* temp;

	temp = s->stk[s->top];
	s->top--;

	return temp;
}

char* peek(stack* s)
{
	if (isEmpty(s))
		return 0;

	char* temp;

	temp = s->stk[s->top];

	return temp;
}

void PrintStack(stack* s)
{
	for (int i = 0; i <= s->top; i++)
		printf("%s", s->stk[i]);

	printf("\n");
}

void Infix_to_Postfix(stack* s, char* input, char* output)
{
	for (int i = 0; i < strlen(input); i++)
	{
		switch (input[i])
		{
		case'+':case'-':
			push(s, &input[i]);
			push(s, "1");
			break;
		case'*':case'/':
			push(s, &input[i]);
			break;
		case'(':case')':
			if (peek(s) != "1")
				push(s, "1");
			break;
		default:
			if (pop(s) != "1")
				strncat(output, input, 1);
			else
				strcat(output, pop(s));
			break;
		}
	}
}

void main()
{
	stack s;
	char input[50];
	char output[50];

	initialize(&s, 50);

	printf("수식을 입력하세요. : \n");
	scanf("%s", input);

	Infix_to_Postfix(&s, input, output);
}