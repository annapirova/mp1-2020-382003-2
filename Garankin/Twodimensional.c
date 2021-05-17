#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void main()
{
	int i, j,t, n,max, maxA;
	int A[100][100];
	max = -1;
	srand(time(0));
	scanf_s("%d", &n);
	for (i=0;i<n;i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand()%100;
		}
	}

	for (i = 0; i < n; i++)
	{
		j = 0;
		if (A[i][j] > max)
		{
			max = A[i][j];
			maxA = i;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < n; j++)
	{
		i = 0;
		t = A[i][j];
		A[i][j] = A[maxA][j];
		A[maxA][j] = t;
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}