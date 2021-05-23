#include <iostream>
#include <cstdlib> 
#include "class.h"
#include <cmath>
using namespace std;

matrix::matrix(int n1, int m1)
{
	n = n1;
	m = m1;
	a = new double*[n * m];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n * m];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			a[i][j] = (rand() % 10);
		}
	}
}

matrix::matrix(const matrix& mat)
{
	int i;
	n = mat.n;
	m = mat.m;
	a = new double*[m * n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n * m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i] = mat.a[i];
		}
	}
}

matrix::~matrix()
{
	delete[] a;
}

double* matrix::operator[](int i)
{
		return a[i];
}

//const double& matrix::operator[](int i, int j) const
//{
//		return a[i][j];
//}

matrix& matrix::operator=(const matrix& mat)
{
	int i;
	if (this == &mat)
		return *this;
	delete[] a;
	a = new double*[n * m];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n * m];
	}
	n = mat.n;
	m = mat.m;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			a[i][j] = mat.a[i][j];
	}
	return *this;
}

matrix matrix::operator+(const matrix& mat) const
{
	double t;
	matrix r(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			r.a[i][j] = a[i][j] + mat.a[i][j];
			//*r[i][j] = t;
		}
	}
	return mat;
}

matrix matrix::operator-(const matrix& mat) const
{
	matrix res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.a[i][j] = a[i][j] - mat.a[i][j];
	return res;
}

matrix matrix::operator*(const matrix& mat) const
{
	matrix res(n, mat.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < mat.a[i][j]; j++)
			res.a[i][j] = a[i][j] + a[i][j] * mat.a[i][j];
	return res;
}

matrix& matrix::operator+=(const matrix& mat)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 0; j++)
			a[i][j] += mat.a[i][j];
	return *this;
}

matrix& matrix::operator-=(const matrix& mat)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 0; j++)
			a[i][j] -= mat.a[i][j];
	return *this;
}