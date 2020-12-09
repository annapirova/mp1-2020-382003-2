#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"

void randArray(double* B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void print(double* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%5.3f ", B[i]);
	printf("\n");
}

void RandArray2d(double** A, int n, int m, int a1, int b1)
{
	int i;
	for (i = 0; i < n; i++)
		randArray(A[i], m, a1, b1);
}

void Print2D_2(double** A, int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
		print(A[i], m);
	printf("\n");
}

void Malloc2d(double*** A, int n, int m)
{
	int i;
	*A = (double**)malloc(sizeof(double*) * n);
	for (i = 0; i < n; i++)
		(*A)[i] = (double*)malloc(sizeof(double) * m);
}

void Free2d(double*** A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free((*A)[i]);
	free(*A);
}

//Умножение матрицы на вектор
/*void Vetors(int A, int n)
{
	int i, j;
	int C[n], B[n];
	for (i = 0; i < n; i++)
	{
		C[i] = 0;
		for (j = 0; j < n; j++)
		{
			C[i] += A[i][j] * B[j]
		}
	}
}*/

double* gauss(double** A, double* Y, double* X, int n)
{
	int k, index;
	double max;
	k = 0;
	while (k < n)
	{
		int  i, j;
		double tmp;
		// ищем строку с максимальным элементом
		max = fabs(A[k][k]);
		index = k;
		for (i = k + 1; i < n; i++)
		{
			if (fabs(A[i][k]) > max)
			{
				max = fabs(A[i][k]);
				index = i;
			}
		}

		if (max == 0)
		{
			printf("Решений не может быть");
			return (0);
		}
		//переставляем строки как положено
		for (j = 0; j < n; j++)
		{
			tmp = A[k][j];
			A[k][j] = A[index][j];
			A[index][j] = tmp;
		}
		tmp = Y[k];
		Y[k] = Y[index];
		Y[index] = tmp;


		//приводим к треугольному виду 
		for (i = k; i < n; i++)
		{
			//tmp = A[i][k];
			////если диагональный элемент != 0
			//if (tmp != 0)
			//{
			//	for (j = 0; j < n; j++)
			//		A[i][j] = A[i][j] / tmp;

			//}
			//Y[i] = Y[i] / tmp;

			//для того чтобы не вычитали из самого себя
			if (i != k)
			{
				for (j = 0; j < n; j++)
					A[i][j] = A[i][j] - A[k][j] * A[i][j];
				Y[i] = Y[i] - Y[k] * A[i][k];
			}
		}
		k++;
	}

	Print2D_2(A, n, n);
	print(Y, n);

	//обратный ход, не понимаю как его правильно сделать
	int i, j;
	X[n - 1] = Y[n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
			Y[i] -= X[j] * A[i][j];
		X[i] = Y[i];
	}
	//printf("X%d = %f\n", i, X[i]);

	/*int i;
	printf("\n");
	printf("Ответ:\n");
	for (i = 0; i < n; i++)
	{
		printf("X%d = %f\n", i, x[i]);
	}
	*/
}


void printresult(double* X, int n)
{
	int i;
	printf("\n");
	printf("Ответ:\n");
	for (i = 0; i < n; i++)
	{
		printf("X%d = %lf\n", i, X[i]);
	}
}

void printmatr(double** A, int n, int m)
{
	printf("Введите матрицу {4 2 -1 5 3 -2 3 2 -3}:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%lf", &A[i][j]);
}

void perem(double* Y, int n)
{
	printf("Введите массив y {1 2 0}:\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf", &Y[i]);
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	double* Y, * X;
	int n = 3;
	int m = 3;
	double** A;
	Y = (double*)malloc(sizeof(double*) * n);
	X = (double*)malloc(sizeof(double*) * n);
	Malloc2d(&A, n, m);

	perem(Y, n);

	//RandArray2d(A, n, m, -1, 5);
	printmatr(A, n, m);
	Print2D_2(A, n, m);

	gauss(A, Y, X, n);

	printresult(X, n);
	//ответ должен быть {-1 3 1}

	Free2d(&A, n);
	free(Y);
	free(X);
}