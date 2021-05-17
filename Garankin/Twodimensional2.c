#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void Print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}


void main()
{
	int i, j, n, k, t, max, min, maxc, maxl, minc, minl, mini,maxi,minj,maxj;
	int A[100][100];
	int saddle[100][100];
	int maxCi[100];
	int minLi[100];
	int maxCj[100];
	int minLj[100];
	int maxLi[100];
	int minCi[100];
	int maxLj[100];
	int minCj[100];
	scanf_s("%d", &n);
	srand(time(0));
	t = 0;
	max = -1;
	min = 1000;
	maxc = max;
	maxl = max;
	minc = min;
	minl = min;
	mini = min;
	minj = min;
	maxi = max;
	maxj = max;

	// Заполнение массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d ", &(A[i][j]));
			//A[i][j] = rand() % 100;
		}
	}

	// Печать массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3d ", A[i][j]);
		}
		printf("\n");
	}

	// Поиск максимальных элементов строк
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] > maxl)
			{
				maxl = A[i][j];
				maxi = i;
				maxj = j;
			}
		}
		maxLi[i] = maxi;
		maxLj[i] = maxj;
		maxl = max;
		maxj = max;
	}
	maxi = max;

	// Поиск максимальных элементов столбцов
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (A[i][j] > maxc)
			{
				maxc = A[i][j];
				maxi = i;
				maxj = j;
			}
		}
		maxCi[j] = maxi;
		maxCj[j] = maxj;
		maxc = max;
		maxi = max;
	}
	maxj = max;

	// Поиск минимальных элементов строк
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] < minl)
			{
				minl = A[i][j];
				mini = i;
				minj = j;
			}
		}
		minLi[i] = mini;
		minLj[i] = minj;
		minl = min;
	}
	mini = min;

	// Поиск минимальных элементов столбцов
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (A[i][j] < minc)
			{
				minc = A[i][j];
				mini = i; 
				minj = j;
			}
		}
		minCi[j] = mini;
		minCj[j] = minj;
		minc = min;
	}
	minj = min;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (maxCi[i] == minLi[j] && maxCj[i] == minLj[j])
				t++;				
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (maxLi[i] == minCi[j] && maxLj[i] == minCj[j])
				t++;
		}
	}
	
	printf("t=%d \n", t);

	/*for (i = 0; i < t; i++)
	{
		for (j = 0; j < t; j++)
		{
			printf("%d ", saddle[i][j]);
		}
		printf("\n");
	}

	*/
		  
}
