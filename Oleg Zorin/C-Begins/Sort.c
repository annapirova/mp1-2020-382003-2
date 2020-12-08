#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "malloc.h"
#include "memory.h"
#include "time.h"

void randArray(int* A, int n)
{
	int i;
	int max = n;
	int min = -n;
	
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % (max - min) + min;
	}
}

void manuallyArray(int* A, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &(A[i]));
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
		for (i = inf; i < sup; i++) 
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
		for (i = sup; i > inf; i--) 
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
	(*nc) += 2;
}

void insertSort(int* A, int n, int* nc, int* nsw)
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
			(*nsw)++;;
			(*nc)++;
		}
		A[j + 1] = temp;
		(*nsw)++;
	}
}

void merge(int* A, int left, int mid, int right, int* nc, int* nsw)
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
			(*nsw)++;
		}
		else
		{
			tempArr[i] = A[ir];
			i++;
			ir++;
			(*nsw)++;
		}
		(*nc)++;
	}
	while (il <= mid)
	{
		tempArr[i] = A[il];
		i++;
		il++;
		(*nsw)++;
	}
	while (ir <= right)
	{
		tempArr[i] = A[ir];
		i++;
		ir++;
		(*nsw)++;
	}
	for (i = 0; i < t; i++)
	{
		A[left + i] = tempArr[i];
	}
	free(tempArr);
}

void mergeSort(int* A, int left, int right, int* nc, int* nsw)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(A, left, mid, &(*nc), &(*nsw));
		mergeSort(A, mid + 1, right, &(*nc), &(*nsw));
		merge(A, left, mid, right, &(*nc), &(*nsw));
	}
	(*nc)++;
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

int binarySearch(int* A, int n, int key, int* nc)
{
	int l = 0;
	int r = n - 1;
	int mid;

	while (l <= r)
	{
		mid = (l + r) / 2;
		(*nc)++;
		if (key < A[mid])
			r = mid - 1;
		else if (key > A[mid])
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}

int linearSearch(int* A, int n, int key, int* nc)
{
	int i;

	(*nc) += 2;
	if (A[n - 1] != key)
		A[n - 1] = key;
	else
		return n - 1;

	for (i = 0; A[i] != key; i++, (*nc)++);

	if (i == n - 1)
		return -1;
	else
		return i;
}

void menu() 
{
	printf("+---------------------+\n");
	printf("| MENU:               |\n");
	printf("|  1. Input           |\n");
	printf("|  2. Print           |\n");
	printf("|  3. Bubble Sort     |\n");
	printf("|  4. Quick Sort      |\n");
	printf("|  5. Insert Sort     |\n");
	printf("|  6. Merge Sort      |\n");
	printf("|  7. Binary Search   |\n");
	printf("|  8. Linear Search   |\n");
	printf("|  0. Exit            |\n");
	printf("|_____________________|\n");
}

void main()
{
	int* Arr = NULL;
	int* ArrCopy = NULL;
	int* ArrSorted = NULL;
	int n, t, z, l, p, key, nkey;
	unsigned long nComp[6], nSwap[5];
	unsigned long nc, nsw;
	bool wasInput = false;
	bool wasNotSorted = true;
	double sortTime[5];
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
			do
			{
				printf("Enter size: ");
				scanf_s("%d", &n);
			} while (n < 0);
			Arr = (int*)malloc(sizeof(int) * n);
			do
			{
				printf(" 1. Manually\n 2. Random\n> ");
				scanf_s("%d", &z);
			} while (z < 1 || z > 2);

			switch (z)
			{
			case 1: {
				manuallyArray(Arr, n);
				break;
			}
			case 2: {
				randArray(Arr, n);
				break;
			}
			}
			ArrSorted = (int*)malloc(sizeof(int) * n);
			wasInput = true;
			break;
		}
		case 2: {
			if (wasInput)
			{
				do
				{
					printf(" 1. Default\n 2. Sorted\n> ");
					scanf_s("%d", &p);
				} while (p < 1 || p > 2);
				if (p == 1)
					print(Arr, n);
				else if (!wasNotSorted)
					print(ArrSorted, n);
				else
					printf("Please, sort the array\n");
				
			}
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

				if (Check(ArrCopy, n)) 
					printf("Sorted correctly\n");
				if (wasNotSorted)
				{
					memcpy(ArrSorted, ArrCopy, sizeof(int) * n);
					wasNotSorted = false;
				}
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);

				sortTime[0] = time;
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

				if (Check(ArrCopy, n)) 
					printf("Sorted correctly\n");
				if (wasNotSorted)
				{
					memcpy(ArrSorted, ArrCopy, sizeof(int) * n);
					wasNotSorted = false;
				}
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);

				sortTime[1] = time;
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
				nc = 0;
				nsw = 0;

				time = clock();
				insertSort(ArrCopy, n, &nc, &nsw);
				time = clock() - time;

				if (Check(ArrCopy, n)) 
					printf("Sorted correctly\n");
				if (wasNotSorted)
				{
					memcpy(ArrSorted, ArrCopy, sizeof(int) * n);
					wasNotSorted = false;
				}
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);

				sortTime[2] = time;
				nComp[2] = nc;
				nSwap[2] = nsw;
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
				nc = 0;
				nsw = 0;

				time = clock();
				mergeSort(ArrCopy, 0, n - 1, &nc, &nsw);
				time = clock() - time;

				if (Check(ArrCopy, n)) 
					printf("Sorted correctly\n");
				if (wasNotSorted)
				{
					memcpy(ArrSorted, ArrCopy, sizeof(int) * n);
					wasNotSorted = false;
				}
				printf("Time: %f sec\n", (double)time / CLOCKS_PER_SEC);
				printf("Swaps: %d, comparisons: %d\n", nsw, nc);
				
				sortTime[3] = time;
				nComp[3] = nc;
				nSwap[3] = nsw;
				free(ArrCopy);
			}
			else
				printf("Please, input array\n");
			break;
		}
		case 7: {
			if (wasInput && !wasNotSorted)
			{
				nc = 0;
				printf("Enter the element: ");
				scanf_s("%d", &key);
				nkey = binarySearch(ArrSorted, n, key, &nc);
				if (nkey == -1)
					printf("Element not found :(\n");
				else
					printf("Element number: %d\n", nkey);
				printf("Comparisons: %d\n", nc);
				nComp[4] = nc;
			}
			else
				printf("Please, sort the array\n");
			break;
		}
		case 8: {
			if (wasInput)
			{
				nc = 0;
				do
				{
					printf("Use array:\n 1. Default\n 2. Sorted\n> ");
					scanf_s("%d", &l);
				} while (l < 1 || l > 2);
				printf("Enter the element: ");
				scanf_s("%d", &key);
				if (l == 1)
					nkey = linearSearch(Arr, n, key, &nc);
				else if (!wasNotSorted)
					nkey = linearSearch(ArrSorted, n, key, &nc);
				else
				{
					nkey = -1;
					printf("Please, sort the array\n");
				}

				if (nkey == -1)
					printf("Element not found :(\n");
				else
					printf("Element number: %d\n", nkey);
				printf("Comparisons: %d\n", nc);
				nComp[5] = nc;
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