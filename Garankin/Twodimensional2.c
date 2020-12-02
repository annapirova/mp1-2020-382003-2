#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void main()
{
	int i, j, n, k, t, max, min, maxI, maxJ, minI, minJ;
	int A[100][100];
	int MaxI[100];
	int MaxJ[100];
	int MinI[100];
	int MinJ[100];
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	srand(time(0));
	maxI = -1;
	minI = 1000;
	maxJ = -1;
	minJ = 1000;

	// Заполнение массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			A[i][j] = rand() % 100;
		}
	}


	// Печать массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			printf("%3d ", A[i][j]);
		}
		printf("\n");
	}


	for (i = 0; i < n; i++)
	{
		
		for (j = 0; j < k; j++)
		{
			if (A[i][j] > maxJ)
			{
				maxJ = A[i][j];
				MaxJ[j] = maxJ;
			}
			else MaxJ[j] = 0;
			if (A[i][j] < minJ)
			{
				minJ = A[i][j];
				MinJ[j] = minJ;
			}
			else MinJ[j] = 0;
			if (A[i][j] > maxI)
			{
				maxI = A[i][j];
				MaxI[i] = maxI;
			}
			else MaxI[i] = 0;
			if (A[i][j] < minI)
			{
				minI = A[i][j];
				MinI[i] = minI;
			}
			else MinI[i] = 0;
		}
	}
	
	printf("%d %d", maxI, minI);
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", MaxI[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", MinI[i]);
	}
	printf("\n");
	for (j = 0; j < k; j++)
	{
		printf("%d ", MaxJ[j]);
	}
	printf("\n"); 
	for (j = 0; j < k; j++)
	{
		printf("%d ", MinJ[j]);
	}
	printf("\n");
	
}