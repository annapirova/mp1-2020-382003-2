// проверка, является ли каждая строка матрицы набором чисел от 1 до N
// переставить 0 и последнюю строки местами

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define N 5

int RowPerestanovka(int** a, int k)
{
	int flag = 1, i;
	int* count = (int*)calloc(N, sizeof(int));
	for (i = 0; i < N && (flag = 0); i++)
		if (a[k][i] >= 1 && a[k][i] <= N)
			count[ a[k][i] ]++;
		else flag = 0;
	for (i = 1; i < N && flag; i++)
		if (count[i] != 1)
			flag = 0;
	
	return flag;
}



void Init(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = rand() % 5;
}


void Print(int* a[N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%e ", a[i][j]);
		printf("\n");
	}
}


int Check(int a[N][N])
{
	int i, j, flag = 1;
	for (i = 0; j < N && flag == 0; j++)
		if (RowPerestanovka(a, i))
			flag = 0;
	return flag;
}

int main()
{
	int** a;
	int* row1, row2;
	int res;
	int i;

	a = (double**)malloc(sizeof(int) * N);
	for (i = 0; i <= N; i++)
		a[i] = (double*)malloc(sizeof(double) * N);

	Init(a);
	Print(a);
	res = Check(a);
	printf("%f\n", res);

	return 0;
}