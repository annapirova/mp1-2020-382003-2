#include "Vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#define EPS 1e-10

vector::vector(int n)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = 0.0;
	}
}

vector::vector(int n, double * v)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = v[i];
	}
}

vector::vector(int n, int max)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	
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

vector vector::operator-(const vector & v) const
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

vector & vector::operator=(double p)
{
	for (int i = 0; i < size; i++)
		value[i] = p;
	return *this;
}

vector operator*(double p, const vector& v)
{
	vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = p * v.value[i];
	}
	return res;
}

vector operator*(const vector& v, double p)
{
	vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = v.value[i] * p;
	}
	return res;
}

double & vector::operator[](int i)
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong number of value");
	return value[i];
}

const double& vector::operator[](int i) const
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong number of value");
	return value[i];
}

bool vector::operator==(const vector& v) const
{
	if (size != v.size)
		return false;

	int i = 0;
	while (i < size)
	{
		if (abs(value[i] - v.value[i]) < EPS)
			i++;
		else
			return false;
	}
	return true;
}

bool vector::operator!=(const vector& v) const
{
	if (size != v.size)
	{
		return true;
	}

	for (int i = 0; i < size; i++)
	{
		if (abs(value[i] - v.value[i]) > EPS)
		{
			return true;
		}
	}
	return false;
}

int vector::GetSize() const
{
	return size;
}

void vector::swap(int a, int b)
{
	double tmp = value[a];
	value[a] = value[b];
	value[b] = tmp;
}

std::ostream & operator<<(std::ostream & os, const vector & v)
{
	os.width(7);
	os.precision(2);
	for (int i = 0; i < v.size; i++)
		os << std::fixed << v.value[i] << " ";
	return os;
}

std::istream& operator>>(std::istream& is, const vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		std::cout << "[" << i << "] = ";
		is >> v.value[i];
	}
	return is;
}