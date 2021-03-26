#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

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
		printf("%3d ", B[i]);
	printf("\n");
}

void RandArray2d(int** A, int n, int m, int a1, int b1)
{
	int i;
	for (i = 0; i < n; i++)
		randArray(A[i], m, a1, b1);
}

void Print2D_2(int** A, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(A[i], m);
	printf("\n");
}

void Malloc2d(int*** A, int n, int m)
{
	int i;
	*A = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		(*A)[i] = (int*)malloc(sizeof(int) * m);
}

void Free2d(int*** A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free((*A)[i]);
	free(*A);
}

void stolb(int** A, int n)
{
	int res, p, k, i;
	printf("Âגוהטעו ןונגûי סעמכבוצ - ");
	scanf_s("%d", &p);
	printf("Âגוהטעו געמנמי סעמכבוצ - ");
	scanf_s("%d", &k);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		res = A[i][p];
		A[i][p] = A[i][k];
		A[i][k] = res;
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n = 3;
	int m = 4;
	int** A;

	Malloc2d(&A, n, m);

	RandArray2d(A, n, m, 1, 10);

	Print2D_2(A, n, m);

	stolb(A, n);

	Print2D_2(A, n, m);

	Free2d(&A, n);
}