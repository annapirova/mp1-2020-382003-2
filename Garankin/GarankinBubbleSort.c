#include "stdio.h"
#include "stdlib.h"


void Print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
}


void BubbleSort(int A[], int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (i % 2 != 0 && A[j] > A[j + 1])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
			if (i % 2 == 0 && A[j+1] < A[j])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
		}
	}
}


void main()
{
	int A[100];
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &(A[i]));
	}
	BubbleSort(A, n);
	Print(A, n);
}


//Гаранькин Георгий