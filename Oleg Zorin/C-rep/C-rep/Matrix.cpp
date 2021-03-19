#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define EPS 1e-10

matrix::matrix(int n , int m)
{
	this->n = n;
	this->m = m;
	A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = 0.0;
}

matrix::matrix(int n, int m, int max)
{
	srand((unsigned int)time(NULL));
	this->n = n;
	this->m = m;
	A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = rand() % max;
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

void matrix::swap(int a, int b)
{
	double temp = 0.0;
	for (int i = 0; i < n; i++)
	{
		temp = A[a][i];
		A[a][i] = A[b][i];
		A[b][i] = temp;
	}
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

matrix matrix::operator+(const matrix& other) const
{
	matrix res(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.A[i][j] = A[i][j] + other.A[i][j];

	return res;
}

matrix matrix::operator-(const matrix& other) const
{
		matrix res(n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res.A[i][j] = A[i][j] - other.A[i][j];

		return res;
}

matrix matrix::operator*(const matrix& other) const
{
		matrix res(n, other.m);

		for (int i = 0; i < res.n; i++)
			for (int j = 0; j < res.m; j++)
			{
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
			res.A[i][j] = other.A[i][j] * p;
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

std::ostream& operator<<(std::ostream& os, const matrix& m)
{
	os.width(7);
	os.precision(2);
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			os << std::fixed << m.A[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, const matrix& m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			std::cout << "[" << i << "][" << j << "] = ";
			is >> m.A[i][j];
		}
	}
	return is;
}

double* matrix::operator[](int i)
{
	if (i >= 0 && i < m)
		return A[i];
	else
		return A[0];
}

const double* matrix::operator[](int i) const
{
	if (i >= 0 && i < n)
		return A[i];
	else
		return A[0];
}
