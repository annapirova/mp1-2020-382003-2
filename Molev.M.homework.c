#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
void DoubleSort(int A[], int n)
{
	int i, j, max = 0, min = 10000, nmax, nmin, change, count = 1;
	ScanArray(A, n);
	for (i = 0; i <= n / 2; i++)
	{
		for (j = i; j < n - count + 1; j++)
		{
			if (A[j] > max)
			{
				max = A[j];
				nmax = j;
			}
			change = A[n - count];
			A[n - count] = A[nmax];
			A[nmax] = change;
			max = 0;
			if (A[j] < min)
			{
				min = A[j];
				nmin = j;
			}
			change = A[i];
			A[i] = A[nmin];
			A[nmin] = change;
			min = 10000;
		}
		count++;
	}
	PrintArray(A, n);
}

void ScanArray(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d\n", &B[i]);
}

void InsertSort(int C[], int n)
{
	int i, j, change;
	ScanArray(C, n);
	for (i = 1; i < n; i++)
	{
		while (i >= 0)
		{
			if (C[i] < C[i - 1])
			{
				change = C[i];
				C[i] = C[i - 1];
				C[i - 1] = change;
			}
			i = i - 1;
		}
	}
	PrintArray(C, n);
}

void PrintArray(int D[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\n", D[i]);
}

void menu()
{
	printf("\nMENU\n");
	printf("1. ScanArray\n");
	printf("2. DoubleSort\n");
	printf("3. InsertSort\n");
	printf("0. Exit\n");
}

void main()
{
	int A[10];
	int n = 10;
	int t = 10;

	printf("start\n");

	while (t != 0)
	{
		menu();
		scanf_s("d", &t);
		switch (t)
		{
		case 1: {
			ScanArray(A, n);
			break;
		}
		case 2: {
			DoubleSort(A, n);
			break;
		}
		case 3: {
			InsertSort(A, n);
			break;
		}
		default: printf("error\n");
			break;
		}
	}
}