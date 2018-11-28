#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
	int top;
	int max;
	char* stk;
}stack;

float calc(float op1, float op2, char operator);

void initialize(stack* s, char max)
{
	s->stk = (char *)calloc(max, sizeof(char) * max);

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

	char temp = s->stk[s->top];
	s->top--;

	return temp;
}

char peek(stack* s)
{
	if (isEmpty(s))
		return 0;

	char temp = s->stk[s->top];

	return temp;
}

void PrintStack(stack* s)
{
	for (int i = 0; i <= s->top; i++)
		printf("%c", s->stk[i]);

	printf("\n");
}

float Evaluation(stack* s, char* input)
{
	char op1, op2;
	float result = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		switch (input[i])
		{
		case'+':case'-':case'*':case'/':
			op1 = pop(s);
			if (result == 0)
			{
				op2 = pop(s);
				result += calc(atof(&op1), atof(&op2), input[i]);
			}
			else
				result = calc(atof(&op1), result, input[i]);
			break;
		default:
			push(s, input[i]);
			break;
		}
	}

	return result;
}

float calc(float op1, float op2, char operator)
{
	float result;

	switch (operator)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	default:
		break;
	}

	return result;
}

void main()
{
	char input[50];
	stack s;

	initialize(&s, 50);

	printf("후위연산수식을 입력하세요 : \n");
	scanf("%s", input);

	printf("%.2f \n",Evaluation(&s, input));
}