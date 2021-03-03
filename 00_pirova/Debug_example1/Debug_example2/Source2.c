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
	for (i = 0; i < N && (flag == 1); i++)
		if (a[k][i] >= 1 && a[k][i] <= N)
			count[ a[k][i] ]++;
		else flag = 0;
	for (i = 1; i < N && (flag == 1); i++)
		if (count[i] != 1)
			flag = 0;
	
	free(count);
	return flag;
}



void Init(int** a)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = rand() % 5;
}


void Print(int** a)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}


int Check(int** a)
{
	int i, flag = 1;
	for (i = 0; i < N && flag == 1; i++)
		if (RowPerestanovka(a, i))
			flag = 0;
	return flag;
}

void Rows(int** a)
{
	int i, tmp;
	for (i = 0; i < N; i++)
	{
		tmp = a[0][i];
		a[0][i] = a[N - 1][i];
		a[N - 1][i] = tmp;
	}
}

int main()
{
	int** a = (int**)malloc(sizeof(int*) * N);
	int res;
	int i;

	for (i = 0; i < N; i++)
		a[i] = (int*)malloc(sizeof(int) * N);

	Init(a);
	Print(a);
	res = Check(a);
	printf("\n%d\n", res);

	Rows(a); // перестановка 0 и (n - 1)
	Print(a);

	for (i = 0; i < N; i++)
		free(a[i]);
	free(a);



	return 0;
}