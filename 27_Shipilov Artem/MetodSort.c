#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "windows.h"
#include "locale.h"

//void print(int B[], int n);

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
	}
}

void InsertSort(int B[], int n)
{
	int s, l, i;
	bool wasSwap;
	for (i = 0; i < n; i++)
	{
		wasSwap = false;
		s = B[i];
		l = i - 1;
		while ((l >= 0) && (B[l] > s))
		{
			B[l + 1] = B[l];
			l = l - 1;
		}
		B[l + 1] = s;
		wasSwap = true;
		if (wasSwap == false)
		{
			break;
		}

	}
}

void CountingSort(int B[], int n, int A[])
{
	int k, i, j;
	for (i = 0; i < n; i++)
	{

		k = 0;
		for (j = 0; j < n; j++)
		{
			//(*nc)++;
			if (B[i] > B[j])
				k++;
		}
		A[k] = B[i];
	}
}

void MergeSort(int* B, int n)
{
	int m, tmp, sh, k, i, j;
	int* A = (int*)malloc(n * sizeof(int));
	m = n / 2;
	if (n % 2 == 1)
		m++;
	tmp = 1;
	while (tmp < n)
	{
		sh = tmp;
		i = 0;
		j = m;
		k = 0; 
		while (sh <= m)
		{
			while ((i < sh) && (j < n) && (j < (m + sh)))
			{
				if (B[i] < B[j])
				{
					A[k] = B[i];
					i++; k++;
				}
				else {
					A[k] = B[j];
					j++; k++;
				}
			}
			while (i < sh)
			{
				A[k] = B[i];
				i++; k++;
			}
			while ((j < (m + sh)) && (j < n))
			{
				A[k] = B[j];
				j++; k++;
			}
			sh = sh + tmp;
		}
		tmp = tmp * 2;
		for (i = 0; i < n; i++)
			B[i] = A[i];
	}
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

void Split(int B[], int left, int right, int* nc, int* nsw)
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
		(*nc)++;
		if (i <= j)
		{
			tmp = B[i];
			B[i] = B[j];
			B[j] = tmp;
			i++;
			j--;
			(*nsw)++;
		}
	}

	// половинка от left до i
	if (left < j)
		Split(B, left, j, nc, nsw);
	// половинка от j до right
	if (i < right)
		Split(B, i, right, nc, nsw);
}

void QuickSort(int B[], int n, int* nc, int* nsw)
{
	Split(B, 0, n - 1, nc, nsw);
}


void menu()
{
	setlocale(LC_CTYPE, "Russian");
	printf("\nMENU:\n");
	printf("1. Ввести массив\n");
	printf("2. Вывести массив\n");
	printf("3. BubbleSort\n");
	printf("4. QuickSort\n");
	printf("5. InsertSort\n");
	printf("6. CountingSort\n");
	printf("7. MergeSort\n");
	printf("0. Выход\n");
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
	setlocale(LC_CTYPE, "Russian");
	int B[100], A[100];
	int n = 100;
	int t = 8;
	bool wasInput = false;
	int nComp[4]; // 0 - сравнения для Bubble, 1 - сравнения для QuickSort,...
	int nSwaps[4]; // 0 - обмены для Bubble, 1 - обмены для QuickSort,...
	printf("Программа по созданию и сортировки массивов с приминением разных методов сортировок\n");
	srand(1000);
	LARGE_INTEGER start, finish, freq;
	double time;
	// для всех сортировок
	double timeAll[4];

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
				memcpy(Bcopy, B, sizeof(int) * n);
				QueryPerformanceCounter(&start);
				BubbleSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[0] = nsw;
				nComp[0] = nc;
				timeAll[0] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("Количество перестановок %d, Количество сравнений %d\n", nsw, nc);
				printf("Время работы программы %lf\n", time);
				BubbleSort(B, n, &nc, &nsw);
				print(B, n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 4: {
			if (wasInput)
			{
				int isCorrect = 0;
				int nc = 0, nsw = 0;
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				QueryPerformanceCounter(&start);
				QuickSort(Bcopy, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[1] = nsw;
				nComp[1] = nc;
				timeAll[1] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("Количество перестановок %d, Количество сравнений %d\n", nsw, nc);
				printf("Время работы программы %lf\n", time);
				QuickSort(B, n, &nc, &nsw);
				print(B, n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 5: {
			if (wasInput == 1)
			{
				int isCorrect = 0;
				int nc = 0, nsw = 0;
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				QueryPerformanceCounter(&start);
				InsertSort(Bcopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[2] = nsw;
				nComp[2] = nc;
				timeAll[2] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("Количество перестановок %d, Количество сравнений %d\n", nsw, nc);
				printf("Время работы программы %lf\n", time);
				InsertSort(B, n);
				print(B, n);
				free(Bcopy);
				}
				else printf("Please, input array\n");
				break;

			}
		case 6: {
				if (wasInput == 1)
				{
			CountingSort(B, n, A);
			print(A, n);
				}
				else printf("Please, input array\n");
				break;

		}
		case 7: {
				if (wasInput == 1)
				{
			MergeSort(B, n);
			print(B, n);
				}
				else printf("Please, input array\n");
				break;
		}
		}
	}

	// сравнить nSwaps, nComp, ...
}

