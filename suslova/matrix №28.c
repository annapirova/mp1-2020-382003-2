#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"

void InputMatr(int a[][5], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d  ", &a[i][j]);
		}
	}
}

void PrintMatr(int a[][5], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}

void InputVector(int y[], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		scanf_s("%d  ", &y[i]);
	}
}

void PrintVector(int y[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("%d  ", y[i]);
	}
}

int Input_and_Output_Array_and_right_vector(int a[][5], int y[5], int n)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		y[i] = rand() % 10;
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
			printf("y[%d] = %d\n", i, y[i]);
	}
	printf("\n");

	//OutputArray(a, n, m);

	return 0;
}

int GaussMethod(int a[][5], int y[], double x[], int n)
{
	int k = 0, index, max;
	k = 0;
	int i, j;
	double tmp;
	while (k < n)
	{
		max = abs(a[k][k]);
		index = k;
		for (i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		if (max == 0)
		{
			printf("íåâîçìîæíî ïîëó÷èòü ðåøåíèå");
			return;
		}

		for (j = 0; j < n; j++)
		{
			tmp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = tmp;
		}
		tmp = y[k];
		y[k] = y[index];
		y[index] = tmp;
		
		for (i = k; i < n; i++)
		{
			tmp = a[i][k];
			if (tmp != 0) 
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = a[i][j] / tmp;
				}
				y[i] = y[i] / tmp;
			}
			if (i == k)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = a[i][j] - a[k][j];
				}
				y[i] = y[i] - y[k];
			}
		}
		k++;
	}

	for (i = 0; i < n; i++)
	{
		x[i] = a[i][n];
		for (i = n - 2; i >= 0; i--)
		{
			for (j = i + 1; j < n; j++)
			{
				y[i] = y[i] - x[j] * a[i][j];
			}
		}
	}
}

void OutputSystem(int a[][5], int y[], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d*x%d", a[i][j], i);
			if (j < n - 1)
			{
				printf(" + ");
			}
		}
		printf(" = %d\n", y[i]);
	}
}

void Result(double x[], int n)
{
	int i;

	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("x[%d] = %lf\n", i, x[i]);
	}
	printf("\n");
}

void main()
{
	int a[5][5], y[5];
	double x[5];
	int n = 3;
	int i;
	double t = 0;

	setlocale(LC_ALL, "rus");

	/*InputMatr(a, n);
	PrintMatr(a, n);
	InputVector(y, n);
	PrintVector(y, n);*/
	Input_and_Output_Array_and_right_vector(a, y, n);
	OutputSystem(a, y, n);
	GaussMethod(a, y, x, n);
	Result(x, n);
	
}
