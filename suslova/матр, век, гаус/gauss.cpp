#include <iostream>
#include <cstdlib> 
#include "class.h"
#include <cmath>
using namespace std;

int Gauss::num(int i, int j, int n)
{
	return (n * i + j);
}

void Gauss::genarr(double** a, int n)
{
	int i, j;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = (rand() % 10);
		}
	}

}

void Gauss::printmatr(matrix& a, int n)
{
	Gauss nu;
	int j, i;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			int g = nu.num(i, j, n);
			cout << a[g] << "\t";
		}
		cout << endl;
	}
}

void Gauss::GaussMethod(matrix a, vector& y, int n, vector& x)
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

void Gauss::Result(char c, vector& x, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << c << i << " = " << x[i] << endl;
	}
}

vector operator*(matrix a, vector& x)
{
	int size = x.GetSize();
	vector res(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i] += a[i][j] * x[j];
		}
	}
	return res;
}
void Gauss::Check(matrix a, vector& x, vector& y, int n)
{
	int size = x.GetSize();
	vector tmp(size);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tmp[i] += a[i][j] * x[j];
		}
		//cout << "y" << i << " = " << tmp[i] << endl;
	}
	if (tmp == y)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "y" << i << " = " << y[i] << endl;
			cout << "succesful" << endl;
		}
	}
	else
		cout << "not succesful" << endl;

}

//void Gauss::Check(matrix& a, vector& x, vector& y, int n)
//{
//	Gauss nu;
//	//vector ycope = y;
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			y[i] += a[nu.num(i, j, n)] * x[j];
//		}
//	}
//	//if (y == ycope)
//	{
//		cout << "y" << i << " = " << y[i] << endl;
//	}
//}

//void Gauss::test(matrix& a, vector& b, vector& r, int n)
//{
//	Gauss nu;
//	double mi;
//	vector c(n), k(n);
//	nu.Check(a, r, c, n);
//	k = c - b;
//	mi = k[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (fabs(k[i]) > fabs(mi))	mi = k[i];
//	}
//	cout << "наибольшее значение по модулю:" << endl;
//	cout << mi << endl;
//}