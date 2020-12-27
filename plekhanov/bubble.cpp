#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void bubblesort(int arrsort[])
{
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			if (arrsort[j] < arrsort[j - 1])
			{
				temp = arrsort[j - 1];
				arrsort[j - 1] = arrsort[j];
				arrsort[j] = temp;
			}
		}
	}
}
void main()
{
	int arr[5];
	printf("enter massive - \n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d ", &arr[i]);
	}
	printf( "\n");
	bubblesort(arr);
	printf("sortmassive - \n");
	for (int i = 0; i < 5; i++)
	{
		printf( "%d ",arr[i], "\n");
	}
}
