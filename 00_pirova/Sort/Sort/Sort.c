#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "memory.h"


void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}


int* myMalloc(int n)
{

	int* B2 = (int*)malloc(sizeof(int) * n);
	return B2;
}


void myMalloc2(int** B, int n)
{
	*B = (int*)malloc(sizeof(int) * n); // это адрес
}

int* myMalloc3(int* n)
{
	int* B2;
	int k;
	printf("Input array size\n");
	scanf_s("%d", n);
	k = *n;
	B2 = (int*)malloc(sizeof(int) * (*n));
	return B2;
}



void main()
{
	int* B;
	int* B2;
	int* B3;

	int n = 100;
	int t = 10;
	bool wasInput = true;

	int* a = (int*)malloc(sizeof(int));
	int k1;
	int k2;

	*a = 4;
	k1 = *a;
	*a = 6;
	k2 = k1 + (*a);
	printf("%d\n", k2);


	printf("start\n");
	srand(1000);

	B = myMalloc3(&n);
	
	myMalloc2(&B2, 10);

	free(B);
	free(B2);
}

