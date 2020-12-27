#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "conio.h"

void main()
{
	int** B;
	int i, j;
	int m, n;
	int range;
	int tmp = 0;
	int k = 0;
	printf("Enter range for Matrix:\n");
	scanf_s("%d", &range);
	printf("Enter number for line:\n");
	scanf_s("%d", &n);
	printf("Enter number for column:\n");
	scanf_s("%d", &m);
	B = (int**)malloc(sizeof(int*) * n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			B[i][j] = rand() % range + 1;
		}
	}

	printf("Matrix\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", B[i][j]);
		}
		printf("\n");
	}
	tmp = B[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (B[i][j] < tmp)
			{
				tmp = B[i][j];
				k = j;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = k; j < m - 1; j++)
		{
			B[i][j] = B[i][j + 1];
		}
	}
	printf("Matrix Edited\n");

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m - 1; y++)
		{
			printf("%d\t", B[x][y]);
		}
		printf("\n");
	}
	free(B);
}