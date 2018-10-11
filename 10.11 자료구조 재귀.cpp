#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void recursive(int num)
{
	if (num <= 0)
		return;

	printf("Recursive call! %d \n", num);
	recursive(num - 1);

	return;
}

int factorial(int n)
{
	if (n < 0)
		return -1;

	if (n == 0)
		return 1;
	else
		return (n*factorial(n - 1));
}

int fibo(int n)
{
	if (n < 1)
		return -1;

	if (n == 1)
		return 0;

	if (n == 2)
		return 1;

	return fibo(n - 1) + fibo(n - 2);
}

// Display how to move n discs in hanoi tower
// n : number of discs
// a : start pole, b : temporary pole, c : goal pole
void hanoi(int n, char* a, char* b, char* c)
{
	if (n == 1)
		printf("Move disc %d from %s to %s \n", n, a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		printf("Move disc %d from %s to %s \n", n, a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main()
{
	char *a = "start";
	char *b = "temp";
	char *c = "goal";

	hanoi(5, a, b, c);

	return 0;
}