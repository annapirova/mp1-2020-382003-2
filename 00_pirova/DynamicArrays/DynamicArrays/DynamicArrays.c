#include "stdio.h"
#include "memory.h"

void myMalloc2(int** B, int n)
{
	*B = (int*)malloc(sizeof(int) * n); // это адрес
}

int* myMalloc(int n)
{

	int* B2 = (int*)malloc(sizeof(int) * n);
	return B2;
}

void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void main()
{
	int* B;
	int n = 5;
}