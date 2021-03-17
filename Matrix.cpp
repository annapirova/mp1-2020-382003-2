#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define EPS 1e-10

matrix::matrix()
{
	n = 1;
	m = 1;
	A = new double* [n];
	A[0] = new double[m];
	A[0][0] = 0;
}

matrix::matrix(int n, int m)
{
	srand((unsigned int)time(NULL));
	this->n = n;
	this->m = m;
	A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = (double)(rand() % 100);
}

matrix::matrix(const matrix& other)
{
	n = other.n;
	m = other.m;
	A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = other.A[i][j];
}

matrix::~matrix()
{
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
		return *this;
	else
	{
		for (int i = 0; i < n; i++)
			delete[] A[i];
		delete[] A;
		n = other.n;
		m = other.m;
		A = new double* [n];
		for (int i = 0; i < n; i++)
			A[i] = new double[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = other.A[i][j];

		return *this;
	}
}

matrix matrix::operator+(const matrix& other)
{
		matrix res(n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.A[i][j] = A[i][j] + other.A[i][j];

		return res;
}

matrix matrix::operator-(const matrix& other)
{
		matrix res(n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.A[i][j] = A[i][j] - other.A[i][j];

		return res;
}

matrix matrix::operator*(const matrix& other)
{
		matrix res(n, other.m);

		for (int i = 0; i < res.n; i++)
			for (int j = 0; j < res.m; j++)
			{
				res.A[i][j] = 0.0;
				for (int l = 0; l < m; l++)
					res.A[i][j] += A[i][l] * other.A[l][j];
			}
		return res;
}

matrix& matrix::operator+=(const matrix& other)
{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] += other.A[i][j];

		return *this;
}

matrix& matrix::operator-=(const matrix& other)
{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] -= other.A[i][j];

		return *this;
}

matrix operator*(const matrix& other, double p)
{
	matrix res(other.n, other.m);

	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
			res.A[i][j] = p * other.A[i][j];

	return res;
}

matrix operator*(double p, const matrix& other)
{
	matrix res(other.n, other.m);

	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
			res.A[i][j] = p * other.A[i][j];

	return res;
}

std::ostream& operator<<(std::ostream& os, const matrix& mat)
{
	for (int i = 0; i < mat.n; i++)
	{
		for (int j = 0; j < mat.m; j++)
		{
			os.width(7);
			os << mat.A[i][j] << " ";
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

double* matrix::operator[](int i)
{
	if (i >= 0 && i < n)
		return A[i];
	else
		return A[0];
}

void matrix::Gauss()
{
	double t1, t2, a;

	for (int k = 1, p = 0; k < n && p < m; k++, p++)
	{
		t1 = A[k - 1][p];

		for (int i = k; i < n; i++)
		{
			if (abs(A[i][p]) < EPS)
				i++;
			else
			{
				t2 = A[i][p];
				a = t2 / t1;
				for (int j = 0; j < m; j++)
					A[i][j] -= A[k - 1][j] * a;
			}
		}
	}
	
}
