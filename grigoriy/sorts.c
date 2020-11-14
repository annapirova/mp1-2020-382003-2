#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

void Menu()
{
	printf("\nMENU:\n");
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. Bubble Sort\n");
	printf("4. Shake Sort\n");
	printf("5. Insert Sort\n");
	printf("6. Shell Sort\n");
	printf("7. Merge Sort\n");
	printf("0. Exit\n\n");
}

void InputRandArray(int *array, int n, int a, int b)
{
	int i;
	srand((unsigned int)time(0));

	for (i = 0; i < n; i++)
		array[i] = rand() % (b - a) + a;
}

void Print(int *array, int n)
{
	int i;

	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void BubbleSort(int *array, int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void ShakeSort(int *array, int n)
{
	int i, j, tmp, l, r;
	l = 0;
	r = n - 1;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (j = l; j < r; j++)
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			r--;
		}
		else
		{
			for (j = r; j > l; j--)
				if (array[j] < array[j - 1])
				{
					tmp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = tmp;
				}
			l++;
		}
	}

}

void InsertSort(int *array, int n)
{
	int i, j, tmp;

	for (i = 1; i < n; i++)
	{
		tmp = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > tmp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

void ShellSort(int *array, int n)
{
	int i, j, tmp, step;

	for (step = (int)(n / 2); step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			tmp = array[i];
			j = i - step;
			while (j >= 0 && array[j] > tmp)
			{
				array[j + step] = array[j];
				j -= step;
			}
			array[j + step] = tmp;
		}
	}
}

void merge(int *array, int l, int middle, int r)
{
	int i, j, k;
	int size_l = middle - l + 1;
	int size_r = r - middle;
	int L[size_l], R[size_r];

	for (i = 0; i < size_l; i++)
		L[i] = array[l + i];
	for (j = 0; j < size_r; j++)
		R[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while(i < size_l && j < size_r)
	{
		if(L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < size_l)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while(j < size_r)
	{
		array[k] = R[j];
		j++;
		k++;
	}

}

void MergeSort(int *array, int l, int r)
{
	if (l < r)
	{
		int middle = l + (int)((r - l) / 2);
		MergeSort(array, l, middle);
		MergeSort(array, middle + 1, r);
		merge(array, l, middle, r);
	}
}

int main()
{
	int A[8];
	unsigned int num;
	int n = 8;
	bool check = false;

	do
	{
		Menu();

		scanf("%d", &num);
		switch (num)
		{
		case 1:
			{
				InputRandArray(A, n, -100, 100);
				check = true;
				break;
			}
		case 2:
			{
				if (check)
					Print(A, n);
				else
					printf("Input array!\n");
				break;
			}
		case 3:
			{
				if (check)
					BubbleSort(A, n);
				else
					printf("Input array!\n");
				break;
			}
		case 4:
			{
				if (check)
					ShakeSort(A, n);
				else
					printf("Input array!\n");
				break;
			}
		case 5:
			{
				if (check)
					InsertSort(A, n);
				else
					printf("Input array!\n");
				break;
			}
		case 6:
			{
				if (check)
					ShellSort(A, n);
				else
					printf("Input array!\n");
				break;
			}
		case 7:
			{
				if (check)
					MergeSort(A, 0, n-1);
				else
					printf("Input array!\n");
				break;
			}
		default:
				printf("\nEnter integer from 0 to 7!\n");
		}
	} while (num != 0);

	return 0;
}
