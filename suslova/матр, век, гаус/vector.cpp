#include <iostream>
#include <cstdlib> 
#include "class.h"
#include <cmath>
#include <ctime>
using namespace std;

vector::vector(int n) //конструктор
{
	size = n;
	a = new double[n];
	for (int i = 0; i < n; i++)
		a[i] = (rand() % 10);
}

vector::vector(const vector& vec) // копирование
{
	size = vec.size;
	a = new double[size];
	for (int i = 0; i < size; i++)
		a[i] = vec.a[i];
}

vector::~vector() // деструктор
{
	delete[] a;
}

//double& vector::operator[](int i) //[]
//{
//	return a[i];
//}

double& vector::operator[](int i)
{
		return a[i];
}

const double& vector::operator[](int i) const
{
		return a[i];
}

vector& vector::operator=(const vector& vec) //=
{
	if (this == &vec)
		return *this;
	delete[] a;
	a = new double[size];
	size = vec.size;
	for (int i = 0; i < size; i++)
	{
		a[i] = vec.a[i];
	}
	return *this;
}

vector vector::operator+(const vector& vec) const
{
	double p;
	vector b(size);
	for (int i = 0; i < size; i++)
	{
		a[i] = a[i] + vec.a[i];
		b.a[i];
	}
	return b;
}

vector vector::operator-(const vector& vec) const
{
	vector res(size);
	for (int i = 0; i < size; i++)
		res[i] = a[i] - vec.a[i];
	return res;
}

vector vector::operator*(const vector& vec) const
{
	double res = 0;
	for (int i = 0; i < size; i++)
		res += a[i] * vec.a[i];
	return res;
}

vector& vector::operator+=(const vector& vec)
{
	for (int i = 0; i < size; i++)
		a[i] += vec.a[i];
	return *this;
}

vector& vector::operator-=(const vector& vec)
{
	for (int i = 0; i < size; i++)
		a[i] -= vec.a[i];
	return *this;
}

bool vector::operator==(const vector& vec)
{
	int i = 0;
	double eps = 0.00001;

	while (i < size)
	{
		if (abs(a[i] - vec.a[i]) < eps)
			i++;
		else
			return false;
	}
	return true;
}

int vector::GetSize() const
{
	return size;
}