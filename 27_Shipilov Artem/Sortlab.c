#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "windows.h"
#include "locale.h"

void BubbleSort(int A[], int n, int* nc, int* nsw)
{
	int tmp;
	int count = 0;
	int left = 0;
	int right = n - 1;
	do {
		for (int i = left; i < right; i++) 
		{
			(*nc)++;
			if (A[i] > A[i + 1]) 
			{
				tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
				count = i;
				(*nsw)++;
			}
		}
		right = count;
		for (int i = right; i > left; i--) 
		{
			(*nc)++;
			if (A[i] < A[i - 1]) 
			{
				tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				count = i;
				(*nsw)++;
			}
		}
		left = count;
	} while (left < right);
}

void InsertSort(int B[], int n, int* nsw)
{
	int i;
	int x = 0, pos = 0;
	for (i = 1; i < n; i++)
	{
		x = B[i];
		pos = i - 1;

		while ((pos >= 0) && (B[pos] > x))
		{
			B[pos + 1] = B[pos];
			(*nsw)++;
			pos--;
		}
		B[pos + 1] = x;
	}
}

void MergeSort(int* B, int n, int* nc, int* nsw)
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
				(*nc)++;
				if (B[i] < B[j])
				{
					A[k] = B[i];
					i++; 
					k++;
					(*nsw)++;
				}
				else {
					A[k] = B[j];
					j++; 
					k++;
					(*nsw)++;
				}
			}
			while (i < sh)
			{
				A[k] = B[i];
				i++; 
				k++;
				(*nsw)++;
			}
			while ((j < (m + sh)) && (j < n))
			{
				A[k] = B[j];
				j++; 
				k++;
				(*nsw)++;
			}
			sh = sh + tmp;
		}
		tmp = tmp * 2;
		for (i = 0; i < n; i++)
			B[i] = A[i];
	}
}

void LinSearch(int* �, int n, int ElementKey, int *SizeKey)
{
	for (int i = 0; i < n; i++)
	{
		if (�[i] == ElementKey)
			(*SizeKey) = i;
		else
			(*SizeKey) = -1;
	}
}

void BinSearch(int* �, int left, int right, int ElementKey, int *SizeKey)
{
	int count = 0;
	while (SizeKey = 0)
	{
		count = (left + right) / 2;

		if (ElementKey < �[count])
			right = count - 1;
		else 
			if (ElementKey > �[count])
				left = count + 1;
			else
				(*SizeKey) = count;
		if (left > right)
			(*SizeKey) = -1;
	}
}

void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void InputSize(int* n)
{
	printf("������� ������ �������:");
	scanf_s("%d", &(*n));
}

void InputArray(int B[], int n)
{
	printf("������ ���� �������:\n");
	for (int i = 0; i < n; i++)
	{
		printf("B[%d]=", i);
		scanf_s("%i", &B[i]);
	}
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
	setlocale(LC_CTYPE, "Russian");
	printf("\nMENU:\n");
	printf("1. ������ ������ �������\n");
	printf("2. ������ ��������� ������\n");
	printf("3. ������ ������ � ����������\n");
	printf("4. ������� ������\n");
	printf("5. BubbleSort\n");
	printf("6. InsertSort\n");
	printf("7. MergeSort\n");
	printf("8. �������� �����\n");
	printf("9. �������� �����\n");
	printf("10. ���������� ������������, ��������� � ����� ������.\n");
	printf("0. �����\n");
}

void menu2()
{
	setlocale(LC_CTYPE, "Russian");
	printf("\nMENU2:\n");
	printf("1. ����� ������ �������� �������� � ��������� �������\n");
	printf("2. ����� ������ �������� �������� � ��������������� �������\n");
	printf("0. �����\n");
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
	int* B = 0, *A = 0, *C = 0;
	int n = 0;
	int t = 10;
	int y = 2;
	int ElementKey = 0, SizeKey = 0;
	bool wasInput = false;
	int nComp[3]; 	
	int nSwaps[3]; 
	printf("��������� �� �������� � ���������� �������� � ����������� ������ ������� ����������\n");
	srand(1000);
	LARGE_INTEGER start, finish, freq;
	double time;
	double timeAll[3];

	QueryPerformanceFrequency(&freq);

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			InputSize(&n);
			break;
		}
		case 2: {
			if (wasInput)
				//			{
				//				free(B);
				//			}
			scanf_s("%d", &n);
			B = (int*)malloc(sizeof(int) * n);
			randArray(B, n, -10, 10);
			wasInput = true;
			break;
		}
		case 3: {
			if (wasInput)
				//			{
				//				free(B);
				//			}
			scanf_s("%d", &n);
			B = (int*)malloc(sizeof(int) * n);
			InputArray(B, n);
			wasInput = true;
			break;
		}
		case 4: {
			if (wasInput)
				print(B, n);
			else printf("Please, input array\n");
			break;
		}
		case 5: {
			if (wasInput == 1)
			{
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				int* � = (int*)malloc(sizeof(int) * n);
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
				printf("���������� ������������ %d, ���������� ��������� %d\n", nsw, nc);
				printf("����� ������ ��������� %lf\n", time);
				BubbleSort(Bcopy, n, &nc, &nsw);
				memcpy(�, Bcopy, sizeof(int) * n);
				print(Bcopy, n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 6: {
			if (wasInput == 1)
			{
				int isCorrect = 0;
				int nc = 0, nsw = 0;
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				int* � = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				QueryPerformanceCounter(&start);
				InsertSort(Bcopy, n, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[1] = nsw;
				nComp[1] = nc;
				timeAll[1] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("���������� ������������ %d, ���������� ��������� %d\n", nsw, nc);
				printf("����� ������ ��������� %lf\n", time);
				InsertSort(Bcopy, n, &nsw);
				print(Bcopy, n);
				memcpy(�, Bcopy, sizeof(int) * n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 7: {
			if (wasInput == 1)
			{
				int nc = 0, nsw = 0;
				int isCorrect = 0;
				int* Bcopy = (int*)malloc(sizeof(int) * n);
				int* � = (int*)malloc(sizeof(int) * n);
				memcpy(Bcopy, B, sizeof(int) * n);
				QueryPerformanceCounter(&start);
				MergeSort(B, n, &nc, &nsw);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
				nSwaps[2] = nsw;
				nComp[2] = nc;
				timeAll[2] = time;
				isCorrect = Check(Bcopy, n);
				printf("isCorrect %d\n", isCorrect);
				printf("���������� ������������ %d, ���������� ��������� %d\n", nsw, nc);
				printf("����� ������ ��������� %lf\n", time);
				MergeSort(Bcopy, n, &nc, &nsw);
				print(Bcopy, n);
				memcpy(�, Bcopy, sizeof(int)* n);
				free(Bcopy);
			}
			else printf("Please, input array\n");
			break;
		}
		case 8: {
			while (y != 0)
			{
				menu2();
				scanf_s("%d", &y);
				switch (y)
				{
				case 1: {
					if (wasInput)
					{
						printf("������� ������� �������:");
						scanf_s("%d", &ElementKey);
						LinSearch(B, n, ElementKey, &SizeKey);
						if (SizeKey != -1)
						{
							printf("������ �������� ��������: %d", SizeKey);
						}
						else
						{
							printf("�������� �������� � ������� ���.");
						}
					}
					else printf("Please, input array\n");
					break;
				}
				case 2: {
					if (wasInput)
					{
						printf("������� ������� �������:");
						scanf_s("%d", &ElementKey);
						BinSearch(C, 0, n, ElementKey, &SizeKey);
						if (SizeKey != -1)
						{
							printf("������ �������� ��������: %d", SizeKey);
						}
						else
						{
							printf("�������� �������� � ������� ���.");
						}
					}
					else printf("Please, input array\n");
					break;
				}
				}
			}
		}
		case 9: {
			if (wasInput)
			{
				printf("������� ������� �������:");
				scanf_s("%d", &ElementKey);
				BinSearch(C, 0, n, ElementKey, &SizeKey);
				if (SizeKey != -1)
				{
					printf("������ �������� ��������:%d", SizeKey);
				}
				else
				{
					printf("�������� �������� � ������� ���.");
				}
			}
			else printf("Please, input array\n");
			break;
		}
		case 10: {
			if (wasInput)
			{
				printf("\n���������� ������������:\n");
				for (int i = 0; i < 3; i++)
					printf("nComp[%d]=%d\t", i, nComp[i]);
				printf("\n");

				printf("\n���������� ���������:\n");
				for (int i = 0; i < 3; i++)
					printf("nSwaps[%d]=%d\t", i, nSwaps[i]);
				printf("\n");

				printf("\n����� ������ ����������:\n");
				for (int i = 0; i < 3; i++)
					printf("timeAll[%d]=%lf\t", i, timeAll[i]);
				printf("\n");
			}
			else printf("Please, input array\n");
			break;
		}
		}
	}
	if (wasInput)
	{
		free(B);
		free(A);
	}
}
