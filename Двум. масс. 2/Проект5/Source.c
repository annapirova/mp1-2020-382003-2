#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

void main()
{
	int **B;
	int	*C;
	int i, j, m, n, sw, z;
	printf("Input lines ");
	scanf_s("%d", &n);
	printf("Input columns ");
	scanf_s("%d", &m);
	B = (int**)malloc(n* sizeof(int*));
	C = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		B[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++)
		{
			printf("B[%d][%d]= ", i, j);
			scanf_s("%d", &B[i][j]);
		}
	}
	z = 0;
	for (i = 0; i < n; i++)
	{
		sw = 1;
		for (j = 0; j < (m / 2); j++)
		{
			if (B[i][j] != B[i][m - j - 1])
				sw = 0;
		}
		if (sw == 1)
		{
			C[z] = i;
			z++;
		}
	}
	for (i = 0; i < z; i++)
		printf("%d\n",C[i]);
	scanf_s("%d", &i);
	for (i = 0; i < n; i++)
	{
		free(B[i]);
	}
	free(B);
	free(C);
}