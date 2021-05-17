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
	int i,k,p;
	for (i = 1; i < n; i++)
	{
		k = A[i];
		p = i - 1;
		while (p >=0 && A[p] > k)
		{
			A[p + 1] = A[p];
			p--;
		}
		A[p + 1] = k;
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