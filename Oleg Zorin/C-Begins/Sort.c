#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "malloc.h"
#include "memory.h"
#include "time.h"

void randArray(int* A, int n)
{
	int i;
	int min = -n / 2;
	int max = n / 2;

	for (i = 0; i < n; i++)
	{
		A[i] = rand() % (max - min) + min;
	}
}

void print(int* A, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void bubbleSort(int* A, int n, int* nc, int* nsw)
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
				(*nsw)++;
			}
			(*nc)++;
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
				(*nsw)++;
			}
			(*nc)++;
		}
		inf = k;
	}
}

void quickSort(int* A, int right, int left, int* nc, int* nsw)
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
			(*nsw)++;
		}
		(*nc)++;	
	}
	
	if (left < j)
		quickSort(A, j, left, &(*nc), &(*nsw));
	if (i < right)
		quickSort(A, right, i, &(*nc), &(*nsw));
}

void insertSort(int* A, int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		temp = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > temp)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
	}
}

void merge(int* A, int left, int mid, int right)
{
	int* tempArr;
	int il, ir, i, t;

	il = left;
	ir = mid + 1;
	i = 0;

	t = right - left + 1;
	tempArr = (int*)malloc(sizeof(int) * t);

	while (il <= mid && ir <= right)
	{
		if (A[il] < A[ir])
		{
			tempArr[i] = A[il];
			i++;
			il++;
		}
		else
		{
			tempArr[i] = A[ir];
			i++;
			ir++;
		}
	}
	while (il <= mid)
	{
		tempArr[i] = A[il];
		i++;
		il++;
	}
	while (ir <= right)
	{
		tempArr[i] = A[ir];
		i++;
		ir++;
	}
	for (i = 0; i < t; i++)
	{
		A[left + i] = tempArr[i];
	}
	free(tempArr);
}

void mergeSort(int* A, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}

}

bool Check(int* A, int n)
{
	int i;
	bool f = true;

	for (i = 0; i < n - 1; i++)
	{
		if (A[i + 1] < A[i])
		{
			f = false;
			break;
		}
	}
	return f;
}

void menu() 
{
	printf("+---------------------+\n");
	printf("| MENU:               |\n");
	printf("|  1. Input           |\n");
	printf("|  2. Print           |\n");
	printf("|  3. BubbleSort      |\n");
	printf("|  4. QuickSort       |\n");
	printf("|  5. InsertSort      |\n");
	printf("|  6. MergeSort       |\n");
	printf("|  0. Exit            |\n");
	printf("|_____________________|\n");
}

void main()
{
	int* Arr = NULL;
	int* ArrCopy = NULL;
	int n, t;
	int nComp[5], nSwap[5];
	int nc, nsw;
	bool wasInput = false;
	clock_t time;

	n = 0;
	menu();
	
	do
	{
		printf(">>> ");
		scanf_s("%d", &t);
		srand(1000);

		switch (t)
		{
		case 1: {
			printf("Enter size: ");
			scanf_s("%d", &n);
			Arr = (int*)malloc(sizeof(int) * n);
			randArray(Arr, n);
			wasInput = true;
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
			{
				ArrCopy = (int*)malloc(sizeof(int) * n);
				memcpy(ArrCopy, Arr, sizeof(int) * n);
				nc = 0;
				nsw = 0;

				time = clock();
				bubbleSort(ArrCopy, n, &nc, &nsw);
				time = clock() - time;

				if (Check(ArrCopy, n)) printf("Sorted correctly\n");
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);

				nComp[0] = nc;
				nSwap[0] = nsw;
				free(ArrCopy);
			}
			else
				printf("Please, input array\n");
			break;
		}
		case 4: {
			if (wasInput)
			{
				ArrCopy = (int*)malloc(sizeof(int) * n);
				memcpy(ArrCopy, Arr, sizeof(int) * n);
				nc = 0;
				nsw = 0;

				time = clock();
				quickSort(ArrCopy, n - 1, 0, &nc, &nsw);
				time = clock() - time;

				if (Check(ArrCopy, n)) printf("Sorted correctly\n");
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);

				nComp[1] = nc;
				nSwap[1] = nsw;
				free(ArrCopy);
			}
			else
				printf("Please, input array\n");
			break;
		}
		case 5: {
			if (wasInput)
			{
				ArrCopy = (int*)malloc(sizeof(int) * n);
				memcpy(ArrCopy, Arr, sizeof(int) * n);

				time = clock();
				insertSort(ArrCopy, n);
				time = clock() - time;

				if (Check(ArrCopy, n)) printf("Sorted correctly\n");
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);

				free(ArrCopy);
			}
			else
				printf("Please, input array\n");
			break;
		}
		case 6: {
			if (wasInput)
			{
				ArrCopy = (int*)malloc(sizeof(int) * n);
				memcpy(ArrCopy, Arr, sizeof(int) * n);

				time = clock();
				mergeSort(ArrCopy, 0, n - 1);
				time = clock() - time;

				if (Check(ArrCopy, n)) printf("Sorted correctly\n");
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);

				free(ArrCopy);
			}
			else
				printf("Please, input array\n");
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
	free(Arr);
}