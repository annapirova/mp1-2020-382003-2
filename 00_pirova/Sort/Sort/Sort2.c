#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


void print(int B[], int n);


void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}


void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}



void main()
{
	int B[10];
	int n = 10;
	int t = 10;

	printf("start\n");
	srand(1000);

	randArray(B, n, -30, 30);
}

