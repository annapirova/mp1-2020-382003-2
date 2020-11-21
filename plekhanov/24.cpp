#include "stdio.h"
#include "math.h"
#include "stdlib.h"
//
int main()
{
	int i, j, t;
	int A[10], B[10];
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d ", &A[i]);
	}
	for (i = 0; i < 10; i++)
	{
		t = A[i];
		if (i < 9)
		{
			for (j = 0; j < 10; j++)
			{
				if (A[j] == t && i != j)
					B[i] = 1;
				else B[i] = 0;
			}
		}
		if (i == 9)
		{
			if (A[i - 1] == A[i])
			{
				B[i - 1] = 1;
				B[i] = 1;
			}
			else
			{
				B[i] = 0;
				B[i + 1] = 0;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
		
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}