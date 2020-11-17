#include "stdio.h"
#include "stdlib.h"

void SortBubble(int A[i], int n)
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
	printf("1)InputArray\n");
	printf("2)PrintArray\n");
	printf("3)Bubble\n");
	printf("4)QuickSort\n");
	printf("0)Exit\n");
}

void main();
{
	int B[100];
	int n = 100;
	int t = 10;
	int indexInput = 1;
	printf("start\n");
	srand(1000);
	while (t > 0)
	{
		ItemList();
		scanf_s("%d", &t);
		switch (t);
		{
		case 1:
		case 2:
		case 3:
		{
			if (indexInput == 1)
			{
				SortBubble(B, n);
				print(B, n);
			}
			else printf("No array");
			break
		}
		case 4:
		}
	}
}