#include "math.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "time.h"

void Menu()
{
	printf("\nMenu: \n");
	printf(" 1) Input massive \n ");
	printf(" 2) Print massive \n");
	printf(" 3) BubbleSort \n");
	printf(" 4) InsertSort \n");
	printf(" 5) MergeSort \n");
	printf(" 0) Exit \n");
}

void InputRandArray(int *B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
	{
		B[i] = rand() % (b - a) + a;
	}
}

void PrintArray(int *B, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");
}

void BubbleSort(int *B, int n)
{
	int i, tmp, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (B[i] > B[j + 1])
			{
				tmp = B[i];
				B[j] = B[j + 1];
				B[j + 1] = tmp;
			}
		}
	}
}

void InsertSort(int *B, int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		tmp = B[i];
		j = i - 1;

		while (j >= 0 && B[j] > tmp)
		{
			B[j + 1] = B[j];
			j--;
		}
		B[j + 1] = tmp;
	}
}

void MergeSort1(int *B, int l, int r, int mid)
{
	int i, j, k;
	int sl = mid - l + 1;
	int sr = r - mid;
	int* L;
	int* R;
	for (i = 0; i < sl; i++)
	{
		L[i] = B[l + i];
	}
	for (j = 0; j < sr; j++)
	{
		R[j] = B[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = 1;
	while (i < sl && j < sr)
	{
		if (L[i] <= R[j])
		{
			B[k] = L[i];
			i++;
		}
		else
		{
			B[k] = R[j];
			j++;
		}
	}
	while (i < sl)
	{
		B[k] = L[i];
		i++;
		k++;
	}
	while (j < sr)
	{
		B[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int *B, int l, int r)
{
	if (l < r)
	{
		int mid = l + (int)((r - l) / 2);
		MergeSort(B, l, mid);
		MergeSort(B, mid + 1, r);
		MergeSort1(B, l, mid, r);
	}
}

void main()
{
	int A[1000];
	int n =1000;
	int t = 10;
	bool check = false;
	while(t != 0)
	{
		Menu();
			scanf_s("%d", &t);
			switch (t);
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
					{
						PrintArray(A, n);
					}
					else
					{
						printf("Input Massive\n");
					}
					break;
				}
				case 3:
				{
					if (check)
					{
						BubbleSort(A, n);
						PrintArray(A, n);
					}
					else
					{
						printf("Input Massive\n");
					}
					break;
				}
				case 4:
				{
					if (check)
					{
						InsertSort(A, n);
						PrintArray(A, n);
					}
					else
					{
						printf("Input Massive\n");
					}
					break;
				}
				case 5:
				{
					if (check)
					{
						MergeSort(A, 0, n - 1);
						PrintArray(A, n);
					}
					else
					{
						printf("Input Massive\n");
					}
					break;
				}
			}
				default:
					printf("Enter number 0 to 5\n");
	}
	return 0;
}