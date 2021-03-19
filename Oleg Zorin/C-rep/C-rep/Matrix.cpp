#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define EPS 1e-10

matrix::matrix(int n = 1, int m = 1)
{
	this->n = n;
	this->m = m;
	M = new vector[m];
	for (int i = 0; i < m; i++)
		M[i] = vector(n);
}

matrix::matrix(int n, int m, int max)
{
	this->n = n;
	this->m = m;
	M = new vector[m];
	for (int i = 0; i < n; i++)
		M[i] = vector(n, max);
}

matrix::matrix(const matrix& other)
{
	n = other.n;
	m = other.m;
	M = new vector[m];
	for (int i = 0; i < m; i++)
		M[i] = other.M[i];
}

matrix::~matrix()
{
	delete[] M;
}

void matrix::swap(int a, int b)
{
	for (int i = 0; i < m; i++)
	{
		M[i].swap(a, b);
	}
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
		return *this;
	else
	{
		delete[] M;
		n = other.n;
		m = other.m;
		M = new vector[n];
		for (int i = 0; i < m; i++)
			M[i] = other.M[i];

		return *this;
	}
}

matrix matrix::operator+(const matrix& other) const
{
	matrix res(n, m);

	for (int i = 0; i < m; i++)
		res.M[i] = M[i] + other.M[i];

	return res;
}

matrix matrix::operator-(const matrix& other) const
{
	matrix res(n, m);

	for (int i = 0; i < m; i++)
		res.M[i] = M[i] - other.M[i];

	return res;
}

matrix matrix::operator*(const matrix& other) const
{
	matrix res(n, other.m);

	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
		{
			for (int l = 0; l < m; l++)
				res.M[j][i] += M[j][l] * other.M[l][i];
		}
	return res;
}

matrix& matrix::operator+=(const matrix& other)
{
	for (int i = 0; i < m; i++)
		M[i] += other.M[i];

	return *this;
}

matrix& matrix::operator-=(const matrix& other)
{
	for (int i = 0; i < n; i++)
		M[i] -= other.M[i];

	return *this;
}

matrix operator*(const matrix& other, double p)
{
	matrix res(other.n, other.m);
	for (int i = 0; i < res.m; i++)
		res.M[i] = other.M[i] * p;
	return res;
}

matrix operator*(double p, const matrix& other)
{
	matrix res(other.n, other.m);
	for (int i = 0; i < res.m; i++)
		res.M[i] = p * other.M[i];
	return res;
}

std::ostream& operator<<(std::ostream& os, const matrix& mat)
{
	for (int i = 0; i < mat.m; i++)
		os << mat.M[i];
	return os;
}

std::istream& operator>>(std::istream& is, const matrix& mat)
{
	for (int i = 0; i < mat.m; i++)
	{
		std::cout << "[" << i << "]";
		is >> mat.M[i];
	}
	return is;
}

vector& matrix::operator[](int i)
{
	if (i >= 0 && i < m)
		return M[i];
	else
		return M[0];
}

const vector& matrix::operator[](int i) const
{
	if (i >= 0 && i < n)
		return M[i];
	else
		return M[0];
}
