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


void InsertSort(int A[], int n)
{
	int i,k,t;
	for (i = 1; i < n; i++)
	{
		k = i;
		while (A[k] < A[k - 1] && k > 0 )
		{
			t=A[k-1];
			A[k - 1] = A[k];
			A[k] = t;
			k=k-1;
		}
	}
}


void main()
{
	int n, i;
	int A[1000];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &(A[i]));
	}
	InsertSort(A, n);
	Print(A, n);

}