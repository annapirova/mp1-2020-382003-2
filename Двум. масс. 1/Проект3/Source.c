#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void main()
{
	double **A;
	double aver;
	int i, j, n, m;
	printf("Input lines ");
	scanf_s("%d", &n);
	printf("Input columns ");
	scanf_s("%d", &m);
	A = (double**)malloc(n*sizeof(double*));
	for (i = 0; i<n; i++)
	{
		A[i] = (double*)malloc(m * sizeof(double));
		for (j = 0; j<m; j++) 
		{
			printf("A[%d][%d] = ", i, j);
			scanf_s("%lf", &A[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		aver = 0;
		for (j = 0; j < m; j++)
			aver = aver + A[i][j];
		aver = aver / m;
		for (j = 0; j < m; j++)
			A[i][j] = A[i][j] - aver;
	}
	for (i = 0; i<n; i++) 
	{
		for (j = 0; j<m; j++) 
		{
			printf("%lf ", A[i][j]); 
		}
		printf("\n");
		free(A[i]);
	}
	free(A);
	scanf_s("%d", &i);
}

