#include "stdio.h"
#include "locale.h"
#include "stdlib.h"


void vvod_array(int A[], int n)
{
	int i;
	srand(1000);

	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 10;
	}
}

void print_array(int A[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", A[i]);
	}
}

void Bubble_sort(int A[], int n)
{
	int i, j, tmp;

	while (A[n] <= A[0])
	{
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (A[i] > A[j])
				{
					tmp = A[j];
					A[j] = A[i];
					A[i] = tmp;
				}
			}
		}

		for (i = n; i > 0; i--)
		{
			for (j = i - 1; j > 0; j--)
			{
				if (A[i] > A[j])
				{
					tmp = A[j];
					A[j] = A[i];
					A[i] = tmp;

				}
			}
		}
	}
}

void insertion_sort(int A[], int n)
{
	int k, l;
	for (int i = 1; i < n; i++)
	{
		k = A[i];
		l = i - 1;
		while (l >= 0 && A[l] > k)
		{
			A[l + 1] = A[l];
			l = l - 1;
		}
		A[l + 1] = k;
	}
}

int A[10];
int B[11];

void merging(int left, int mid, int right)
{
	int s, f, i;

	for (s = left, f = mid + 1, i = left; s <= mid && f <= right; i++)
	{
		if (A[s] <= A[f])
		{
			B[i] = A[s++];
		}
		else
		{
			B[i] = A[f++];
		}
	}

	while (s <= mid)
	{
		B[i++] = A[s++];
	}

	while (f <= right)
	{
		B[i++] = A[f++];
	}

	for (i = left; i <= right; i++)
	{
		A[i] = B[i];
	}
}

void merge_sort(int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merging(left, mid, right);
	}
}

void menu()
{
	{
		printf("\nMENU:\n");
		printf("1. Ввод массива\n");
		printf("2. Печать массива\n");
		printf("3. Сортировка пузырьком\n");
		printf("4. Сортировка вставками\n");
		printf("5. Сортировка слиянием\n");
		printf("0. exit\n");
	}
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[10];
	int n = 10;
	int t = 10;

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			vvod_array(A, n);
			break;
		}
		case 2:
		{
			print_array(A, n);
			break;
		}
		case 3:
		{
			Bubble_sort(A, n);
			print_array(A, n);
			break;
		}
		case 4:
		{
			insertion_sort(A, n);
			print_array(A, n);
			break;
		}
		case 5:
		{
			merge_sort(A, n);
			print_array(A, n);
			break;
		}
		}
	}
}