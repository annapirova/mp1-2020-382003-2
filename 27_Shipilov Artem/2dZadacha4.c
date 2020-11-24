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

void MatMult(int** A, int** A2, int** C, int n, int m)
{
	int i, j, k, sum;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum = 0;
			for (k = 0; k < m; k++)
				sum += A[i][k] * A2[k][j];
			C[i][j] = sum;
		}
	}
}

void UnitArray(int** B, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j) 
				B[i][j] = 1;
			else 
				B[i][j] = 0;
		}
	}
}

void ComparisonArray(int** A2, int** B, int n)
{
	int i, j, k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; i++)
		{
			if (A2[i][j] == B[i][j])
				printf("Матрица ортнормированная\n");
			else
				printf("Матрица не ортнормированная\n");
		}
	}
}

void TransposeArray(int** A2, int** A, int n, int m)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			A2[j][i] = A[i][j];
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int** B, *B2;
	int n = 3;
	int m = 4;
	int i, j;
	int** A;
	int** A2;
	int** C;

	Malloc2d(&A, n, m);
	Malloc2d(&A2, m, n);
	Malloc2d(&C, n, n);
	Malloc2d(&B, n, n);

	RandArray2d(A, n, m, -1, 5);

	printf("Обычная матрица:\n");
	Print2D_2(A, n, m);
	
	printf("Транспонированная матрица:\n");
	TransposeArray(A2, A, n, m);
	Print2D_2(A2, m, n);

	printf("Единичная матрица:\n");
	UnitArray(B, n);
	Print2D_2(B, n, n);

	printf("Произведение обычной и транспонированной матрицы\n");
	MatMult(A, A2, C, n, m);
	Print2D_2(C, n, n);

	ComparisonArray(A2, B, n);

	Free2d(&A, n);
	Free2d(&A2, n);
	Free2d(&C, n);
	Free2d(&B, n);
}