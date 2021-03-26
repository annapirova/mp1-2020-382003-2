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

void MinElementDiagonalArray(int** B, int n, int k)
{
	int i, j;
	int min = B[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				if (B[i][j] < min)
				{
					min = B[i][j];
					k = i;
				}
		}
	}
}

void TransformationArray(int** B, int n, int k)
{
	int j;
	for (j = 0; j < n; j++)
	{
		while (j <= n / 2)
		{
			B[k][j] = B[k][n - j - 1];
		}
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int** B;
	int i, j;
	int n = 4;
	int m = n;
	int k = 0;

	Malloc2d(&B, n, n);

	RandArray2d(B, n, m, -1, 5);
	printf("Mатрица:\n");
	Print2D_2(B, n, m);

	printf("Новая матрица:\n");
	MinElementDiagonalArray(B, n, k);

	printf("%d \n", &k);

	TransformationArray(B, n, k);
	//Print2D_2(B, n, m);
	
	Free2d(&B, n);
}