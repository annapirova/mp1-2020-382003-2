#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "");
	int** arr = NULL;
	int n = 0;
	printf("Введите количество строк\n");
	scanf_s("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);//Выделение памяти
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int*) * n);
	}
	srand(time(NULL));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 51 - 25;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}

	int t1[100] = { 0 }, t2[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			t1[i] += arr[i + j][j];
			t2[i] += arr[j][i + j];
		}
	}
	printf("\n");
	printf("Сумма диагоналей под главной диагональю: ");
	for (int i = n - 1; i > 0; i--)
	{
		printf("%d ", t1[i]);
	}
	printf("\n");
	printf("Сумма диагоналей над главной диагональю: ");
	for (int i = 1; i < n; ++i)
	{
		printf("%d ", t2[i]);
	}

	for (int i = 0; i < n; i++)//освобождение памяти
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}