#include "stdio.h"
#include "stdlib.h"

void randArray(int* B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

// A[i, j] = A[i, j] + A2[i, j]
void MatPlusEq(int* A, int* A2, int n, int m)
{
	int size = n * m;
	int i;
	for (i = 0; i < size; i++)
		A[i] += A2[i];
}

// A[i, j] = A[i, j] + A2[i, j]
void MatPlusEq2(int* A, int* A2, int n, int m)
{
	int i, j;
	// [i, j] --> [i*m + j]
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			A[i * m + j] += A2[i * m + j];
}

void Print2D(int* B, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(&(B[i * m]), m);
	printf("\n");
}

void main()
{
	int* B, *B2;
	int n = 5, m = 3;
	int i, j;
	// матрица размера n * m
	B = (int*)malloc(sizeof(int) * n * m);
	B2 = (int*)malloc(sizeof(int) * n * m);
	randArray(B, n * m, -5, 30);
	randArray(B2, n * m, 2, 17);
	// [i, j] --> [i*m + j]
	// 0я строка с 0 по m - 1 инд
	//1я строка с m по m + m - 1 = 2m-1
	Print2D(B, n, m);
	Print2D(B2, n, m);
	MatPlusEq2(B, B2, n, m);
	Print2D(B, n, m);

	free(B);
	free(B2);
}