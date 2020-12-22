#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

#define M 4

void Task20()
{
	int** A;
	int n = 0, p = 0;
	printf("Введите количество сотрудников на предприятии:\n");
	scanf_s("%d", &n);
	A = (int**)malloc(M * sizeof(int*)+n*M*sizeof(int));
	int* start = (int*)((char*)A + M * sizeof(int*));
	for (int i = 0; i < M; i++)
		A[i] = start + i * n;
	for (int i2 = 0, x = 1; i2 <= n; i2++)
	{
		A[0][i2] = x;
		x++;
	}
	printf("Введите T количество часов каждому сотруднику\n");
	for (int i2 = 0; i2 < n; i2++)
	{
		printf("№%d T=", A[0][i2]);
		scanf_s("%d", &A[1][i2]);
		printf("\n");
	}
	printf("Введите Z заработную плату в час каждому сотруднику\n");
	for (int i2 = 0; i2 < n; i2++)
	{
		printf("№:%d T=%d Z=", A[0][i2], A[1][i2]);
		scanf_s("%d", &A[2][i2]);
		printf("\n");
	}
	for (int i2 = 0; i2 < n; i2++)
	{
		A[3][i2] = A[1][i2] * A[2][i2];
		p += A[3][i2];
	}
	printf("№ Сотрудника |T Кол-во часов в месяце |Z Зар. плата в час |S Зарплата в месяц \n");
	for (int i2 = 0; i2 < n; i2++)
	{
		printf("%d			%d			%d		%d\n", A[0][i2], A[1][i2], A[2][i2], A[3][i2]);
	}
	printf("Ежемесячный общий фонд зарплаты предприятия P=%d\n", p);
	free(A);
}

void ArrayFree(int** A, int N)
{
	for (int i = 0; i < N; i++) {
		free(A[i]);
	}
	free(A);
}

void print2dArr(int **A, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			printf("	%d ", A[i][i2]);
		}
		printf("\n");
	}
}

int** ArrayAlloc(int m, int n)
{
	int** A = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		A[i] = (int*)malloc(n * sizeof(int));
	}
	return A;
}

void Task9()
{
	int m = 0, n = 0;
	int j = 0, k = 0;
	printf("Введите размеры матрицы m= n=\n");
	scanf_s("%d %d", &m, &n);
	int** A = ArrayAlloc(m, n);
	j = n + 1;
	k = n + 1;
	for (int i = 0; i < m; i++)
	{
		for (int i2 = 0, x = 1; i2 < n; i2++)
		{
			A[i][i2] = x;
			x++;
		}
	}
	print2dArr(A, m, n);
	while ((j >= n) && (k >= n))
	{
		printf("Введите номера столбцов, которые хотите поменять j и k\n");
		scanf_s("%d %d", &j, &k);
		j -= 1;
		k -= 1;
		if ((j > n) || (k > n))
			printf("Пожалуйста, введите номера столбцов не больше размера n\n");
	}
	for (int i = 0; i < m; i++)
	{
		int tmp = 0;
		tmp = A[i][j];
		A[i][j] = A[i][k];
		A[i][k] = tmp;
	}
	printf("Получившаяся матрица:\n");
	print2dArr(A, m, n);
	ArrayFree(A, m);
}

void menu()
{
	printf("\nMENU:\n");
	printf("1. Задание 9\n");
	printf("2. Задание 20\n");
	printf("0. Exit\n");
}

void main()
{
	setlocale(LC_ALL, "rus");
	int t=10;
	printf("Работа с многомерными массивами\n");
	while (t != 0)
	{
		menu();
		scanf_s("%i", &t);
		switch (t)
		{
		case 1:
		{
			Task9();
			break;
		}
		case 2:
		{
			Task20();
			break;
		}
		}
	}
	return;
}
