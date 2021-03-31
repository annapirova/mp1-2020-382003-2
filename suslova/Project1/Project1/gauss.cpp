#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"
#include "gauss.h"
using namespace std;

void Gauss::InputMatr(double** a, int n)
{
	int i, j;

	srand(1000);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
			cout << "  " << a[i][j];
		}
		cout << endl;
	}
}

void Gauss::InputVectorX(double* y, double* x, double** a, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		x[i] = rand() % 10;
	}
	
	for (i = 0; i < n; i++)
	{
		y[i] = 0;
		for (j = 0; j < n; j++)
		{
			y[i] += a[i][j] * x[j];
		}
	}
}

void Gauss::GaussMethod(double** a, double* y, int n, double* x)
{
	double max, temp, d, sum;
	int k, imax, i, j;
	double eps = 0.00001;
	k = 0;

	//прямой ход
	while (k < n)
	{
		//поиск максимального элемента
		max = fabs(a[k][k]);
		imax = k;
		for (i = k + 1; i < n; i++)
		{
			if (fabs(a[i][k]) > max)
			{
				max = fabs(a[i][k]);
				imax = i;
			}
		}

		if (max == 0)
		{
			cout << "решение получить невозможно" << endl;
		}
		//перестановка строк

		for (j = 0; j < n; j++)
		{
			temp = a[k][j];
			a[k][j] = a[imax][j];
			a[imax][j] = temp;
		}
		temp = y[k];
		y[k] = y[imax];
		y[imax] = temp;

		//деление на первый ненулевой элемент в строке, вычитание 
		for (i = k; i < n; i++)
		{
			temp = a[i][k];
			if (fabs(temp) != 0)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = a[i][j] / temp;
				}
				y[i] = y[i] / temp;
			}



			for (i = k; i < n; i++)
			{
				for (j = i; j < n; j++)
				{
					a[i][j] = a[i][j] - a[k][j];
				}
			}
			y[i] = y[i] - y[k];

			k++;
		}
		//k++;
		//обратный ход
		x[n] = y[n];
		for (i = n - 1; i >= 0; i--)
		{
			sum = 0;
			for (j = i + 1; j < n; j++)
			{
				d = a[i][j] * x[j];
				sum = sum + d;
			}
			x[j] = y[j] - sum;
		}
	}
}

void Gauss::Result(char c, double* x, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << c << i << " = " << x[i] << endl;
	}
}