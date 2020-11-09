#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


void print(int B[], int n);


void BubbleSort(int A[], int n)
{
	int i, j;
	int tmp;
	bool wasSwap;

	for (i = 0; i < n; i++)
	{
		wasSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				wasSwap = true;
			}
		}
		if (!wasSwap) // wasSwap == false
		{
			break;
		}

		print(A, n);
	}

	printf("i = %d\n", i);
}


void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void sortedArray(int B[], int n)
{
	int i; int tmp;
	for (i = 0; i < n; i++)
		B[i] = i;

	tmp = B[n - 2];
	B[n - 2] = B[n - 1];
	B[n - 1] = tmp;
}

void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void menu()
{
	printf("\nMENU:\n");
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. BubbleSort\n");
	printf("4. QuickSort\n");
	printf("0. Exit\n");
}

void Split(int B[], int left, int right)
{
	int mid, i, j, tmp;

	mid = B[(right + left) / 2];
	i = left;
	j = right;

	//printf("mid %d left %d right %d\n", mid, left, right);

	while (i < j)
	{
		while (B[i] < mid)
		{
			i++;
		}
		while (B[j] > mid) 
		{
			j--;
		}

		if (i <= j) // <=
		{
			tmp = B[i];
			B[i] = B[j];
			B[j] = tmp;
			i++;
			j--;
		}
	}
	 
	//printf("=> i %d j %d\n", i, j);

	// половинка от left до i
	if (left < j)
		Split(B, left, j);
	// половинка от j до right
	if (i < right)
		Split(B, i, right);
}

void QuickSort(int B[], int n)
{
	Split(B, 0, n - 1);
}

int Check(int B[], int n)
{
	bool f = true;
	int i;

	for (i = 0; i < n - 1; i++)
	{
		if (B[i + 1] < B[i])
		{
			f = false;
			break;
		}
	}
	return f;
}


void main()
{
	int B[100];
	int n = 100;
	int t = 10;
	bool wasInput = true;

	printf("start\n");
	srand(1000);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
//			sortedArray(B, n);
			randArray(B, n, -10, 10); 
			wasInput = true;
			break;
		}
		case 2: {
			if (wasInput)
				print(B, n);
			else printf("Please, input array\n");
			break;
		}
		case 3: {
			if (wasInput == 1)
			{
				BubbleSort(B, n);
				print(B, n);
			}
			else printf("Please, input array\n");
			break;
		}
		case 4: {
			if (wasInput == 1)
			{
				QuickSort(B, n);
				if (Check(B, n))
					printf("correct\n");
				else
					printf("error\n");
				print(B, n);
			}
			else printf("Please, input array\n");
			break;
		}
		}
	}
}

