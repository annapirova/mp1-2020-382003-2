#include "Vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

vector::vector(int n)
{
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = 0.0;
	}
}

vector::vector(int n, double * v)
{
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = v[i];
	}
}

vector::vector(int n, int max)
{
	srand((unsigned int)time(NULL));
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = (double)(rand() % max); 
	}
}

vector::vector(const vector & v)
{
	size = v.size;
	value = new double[size];
	for (int i = 0; i < size; i++)
	{
		value[i] = v.value[i];
	}
}

vector::~vector()
{
	delete[] value;
}

vector & vector::operator=(const vector & v)
{
	if (this == &v)
		return *this;
	else if (size == v.size)
	{
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
	else
	{
		delete[] value;

		size = v.size;
		value = new double[size];
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
}

vector vector::operator+(const vector & v) const
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] + v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = v.value[i];
	return res;
}

vector vector::operator-(const vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] - v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = -v.value[i];
	return res;
}

vector vector::operator*(const vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	vector res(max);
	for (i = 0; i < min; i++)
		res.value[i] = value[i] * v.value[i];
	return res;
}

vector & vector::operator-=(const vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] - v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = -v.value[i];
	delete[] value;
	size = max;
	value = res;
	return *this;
}

vector & vector::operator+=(const vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] + v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = v.value[i];
	delete[] value;
	value = res;
	size = max;
	return *this;
}

vector & vector::operator*=(const vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] * v.value[i];
	for (i = min; i < max; i++)
		res[i] = 0;
	delete[] value;
	value = res;
	size = max;
	return *this;
}

double & vector::operator[](int i)
{
	if (i >= 0 && i < size)
		return value[i];
	else
		return value[0];
}

std::ostream & operator<<(std::ostream & os, const vector & v)
{
	for (int i = 0; i < v.size; i++)
		os << v.value[i] << "\t";
	os << std::endl;
	return os;
}
