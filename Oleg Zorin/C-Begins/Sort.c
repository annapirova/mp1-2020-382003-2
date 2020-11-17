#define _USE_MATH_DEFINES
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

void randArray(int A[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % (b - a) + a;
	}
}

void print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void bubbleSort(int A[], int n)
{
	int i, k, inf, sup, temp;

	k = 0;
	inf = 0;
	sup = n - 1;

	while (inf < sup)
	{
		for (i = inf; i < sup; i++) // всплывает
		{
			if (A[i] > A[i + 1])
			{
				temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
				k = i;
			}
		}
		sup = k;
		for (i = sup; i > inf; i--) // тонет
		{
			if (A[i] < A[i - 1])
			{
				temp = A[i - 1];
				A[i - 1] = A[i];
				A[i] = temp;
				k = i;
			}
		}
		inf = k;
	}
}

void quickSort(int A[], int right, int left)
{
	int mid, i, j, temp;
	
	mid = A[(left + right) / 2];
	i = left;
	j = right;

	while (i <= j)
	{
		while (A[i] < mid)
		{
			i++;
		}
		while (A[j] > mid)
		{
			j--;
		}
		if (i <= j) 
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
		
	}
	
	if (left < j)
		quickSort(A, j, left);
	if (i < right)
		quickSort(A, right, i);
}

void menu() 
{
	printf("\nMENU\n");
	printf("1. Input\n");
	printf("2. Print\n");
	printf("3. BubbleSort\n");
	printf("4. QuickSort\n");
	printf("0. Exit\n");
}

void main()
{
	int Arr[100], n, t;
	bool wasInput = false;
	n = 10;

	printf("Start\n");
	do
	{
		menu();
		scanf_s("%d", &t);
		srand(10);

		switch (t)
		{
		case 1: {
			randArray(Arr, n, -10, 10);
			wasInput = true;
			print(Arr, n);
			break;
		}
		case 2: {
			if (wasInput)
				print(Arr, n);
			else
				printf("Please, input array\n");
			break;
		}
		case 3: {
			if (wasInput)
				bubbleSort(Arr, n);
			else
				printf("Please, input array\n");
			print(Arr, n);
			break;
		}
		case 4: {
			if (wasInput)
				quickSort(Arr, n - 1, 0);
			else
				printf("Please, input array\n");
			print(Arr, n);
			break;
		}
		case 0: {
			break;
		}
		default:
			printf("Error\n");
			break;
		}
	} while (t != 0);
}