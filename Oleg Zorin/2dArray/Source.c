#include "stdio.h"
#include "stdlib.h"

void malloc2d(int*** A, int n, int m)
{
	int i;
	*A = (int**)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		(*A)[i] = (int*)malloc(sizeof(int) * m);
	}
}

void print(int** A, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%3d ", A[i][j]);
		printf("\n");
	}
	printf("\n");
}

void randArray(int** A, int n, int m, int a, int b)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			A[i][j] = rand() % (b - a) + a;
}

void free2d(int*** A, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free((*A)[i]);
	free(*A);
}

int maxArray(int** A, int n, int m)
{
	int i, j, max;

	max = A[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i][j] > max)
			{
				max = A[i][j];
			}
		}
	}
	return max;
}

int minArray(int** A, int n, int m)
{
	int i, j, min;

	min = A[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i][j] < min)
			{
				min = A[i][j];
			}
		}
	}
	return min;
}

void Task7()
{
	int** Arr;
	int n, m, max, min, raz;

	printf("Enter size: ");
	scanf_s("%d %d", &n, &m);
	malloc2d(&Arr, n, m);
	randArray(Arr, n, m, -10, 20);
	print(Arr, n, m);
	max = maxArray(Arr, n, m);
	printf("Maximum of elements: %d\n", max);
	min = minArray(Arr, n, m);
	printf("Minimum of elements: %d\n", min);
	free2d(&Arr, n);
	raz = max - min;
	printf("Difference of elements: %d\n", raz);
	
}

void CountingMarks(int** A, int n, int m, int M[])
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i][j] == 1)
				M[0]++;
			else if (A[i][j] == 2)
				M[1]++;
			else if (A[i][j] == 3)
				M[2]++;
			else if (A[i][j] == 4)
				M[3]++;
			else
				M[4]++;
		}
	}
}

void Task19()
{
	int** Arr;
	int Marks[5];
	int n, i;

	for (i = 0; i < 5; i++)
	{
		Marks[i] = 0;
	}

	printf("Enter the number of students: ");
	scanf_s("%d", &n);
	malloc2d(&Arr, n, 3);
	randArray(Arr, n, 3, 1, 6);
	print(Arr, n, 3);
	CountingMarks(Arr, n, 3, Marks);
	printf("No-shows - %d, unsatisfactorily - %d, satisfactorily - %d, good - %d, excellent - %d.\n", Marks[0], Marks[1], Marks[2], Marks[3], Marks[4]);
	free2d(&Arr, n);
}

void main()
{
	int t = 0;

	printf("Tasks:\n 1. Seven;\n 2. Nineteen.\n0. Exit.\n");
	do
	{
		printf(">>> ");
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			Task7();
			break;
		}
		case 2: {
			Task19();
			break;
		}
		default:
			break;
		}
	} while (t != 0);
}