#include "stdio.h"
#include "stdlib.h"

void SortBubble(int* A, int n)
{
	int tmp, i, j;
	char bl;
	for (i = 0; i < n; i++)
	{
		bl = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j + 1] < A[j])
			{
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
				bl = 1;
			}
		}
		if (bl = 0)
			break;
	}
}

void ItemList()
{
	printf("\nMenu:\n");
	printf("1)Input array\n");
	printf("2)Print array\n");
	printf("3)Bubble sort\n");
	printf("4)Sort by inserts\n");
	printf("0)Exit\n");
}

void randArray(int B[], int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d  ", B[i]);
	printf("\n");
}

int Check(int *B, int n)
{
	int f = 1;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (B[i + 1] < B[i])
		{
			f = 0;
			break;
		}
	}
	return f;
}

void SortByInserts(int* A, int n)
{
	int i, j, tmp, z;
	for (i = 1; i < n; i++)
	{
		tmp = A[i];
		for (j = 0; j < i - 1; j++)
		{
			if (tmp < A[j])
			{
				for (z = i - 1; z > j; z--)
				{
					A[z + 1] = A[z];
				}
				A[j] = tmp;
				break;
			}
		}
	}
}

void main()
{
	int B[100];
	int n = 100;
	int t = 10;
	int indexInput = 0;
	printf("start\n");
	srand(1000);
	while (t > 0)
	{
		ItemList();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			randArray(B, n, -100, 100);
			indexInput = 1;
			break;
		}
		case 2:
		{
			if (indexInput == 1)
				print(B, n);
			else printf("No array\n");
			break;
		}
		case 3:
		{
			if (indexInput == 1)
			{
				SortBubble(B, n);
				print(B, n);
			}
			else printf("No array\n");
			break;
		}
		case 4:
		{
			if (indexInput == 1)
			{
				SortByInserts(B, n);
				print(B, n);
			}
			else printf("No array\n");
			break;
		}
		}
	}
}