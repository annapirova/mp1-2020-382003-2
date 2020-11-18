#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "windows.h"

void print(int B[], int n);

void BubbleSort1(int A[], int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}

		print(A, n);
	}
}

void BubbleSort(int A[], int n, int* nc, int* nsw)
{
	int i, j;
	int tmp;
	bool wasSwap;

	for (i = 0; i < n; i++)
	{
		wasSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			(*nc)++;
			if (A[j] > A[j + 1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				(*nsw)++;
				wasSwap = true;
			}
		}
		if (wasSwap == false)
		{
			break;
		}

		//print(A, n);
	}

	//printf("i = %d\n", i);
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

void Split(int B[], int left, int right)
{
	int mid, i, j, tmp;

	mid = B[(right + left) / 2];
	i = left;
	j = right;

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


void menu()
{
	printf("\nMENU:\n");
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. BubbleSort\n");
	printf("4. QuickSort\n");
	printf("0. Exit\n");
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
	int B[1000];
	int n = 1000;
	int t = 10;
	bool wasInput = true;
	int nComp[5]; // 0 - сравнения для Bubble, 1 - сравнения для QuickSort,...
	int nSwaps[5]; // 0 - обмены для Bubble, 1 - обмены для QuickSort,...
	printf("start\n");
	srand(1000);
	LARGE_INTEGER start, finish, freq;
	double time;

	// для всех сортировок
	double timeAll[5];

	QueryPerformanceFrequency(&freq);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			//sortedArray(B, n);
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
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				int nc = 0, nsw = 0;
				int isCorrect = 0;
				//копирую содержимое массива
				memcpy(Bcopy, B, sizeof(int)*n);

				QueryPerformanceCounter(&start);
				BubbleSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[0] = nsw;
				nComp[0] = nc;
				timeAll[0] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("swaps %d comparisons %d\n", nsw, nc);
				printf("time %lf\n", time);
				//print(B, n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 4: {
			if (wasInput)
			{
				int isCorrect;
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				//копирую содержимое массива
				memcpy(Bcopy, B, sizeof(int) * n);
				QuickSort(Bcopy, n);
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		}
	}

	// сравнить nSwaps, nComp, ...
}


