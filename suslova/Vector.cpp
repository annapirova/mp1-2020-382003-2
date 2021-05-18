#include <iostream>
#include "Vector.h"

Vector::Vector(int n)
{
	Vec = (double*)malloc(sizeof(double) * n);
}

Vector::Vector(const Vector& V)
{
	n = V.n;
	Vec = (double*)malloc(sizeof(double) * n);
}

Vector::~Vector()
{
	delete[] Vec;
}

Vector Vector::operator+(const Vector& V) const 
{
    Vector tmp(n);
    for (int i = 0; i < n; i++) {
        tmp.Vec[i] = Vec[i] + V.Vec[i];
    }
    return tmp;
}

Vector Vector::operator-(const Vector& V) const 
{
    Vector tmp(n);
    for (int i = 0; i < n; i++) {
        tmp.Vec[i] = Vec[i] - V.Vec[i];
    }
    return tmp;
}

Vector operator*(double var, const Vector& V) 
{
    return Vector(V * var);
}

Vector& Vector::operator+=(const Vector& V) 
{
    for (int i = 0; i < n; i++) 
    {
        Vec[i] += V.Vec[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& V) 
{
    for (int i = 0; i < n; i++) 
    {
        Vec[i] -= V.Vec[i];
    }
    return *this;
}

Vector& Vector::operator=(const Vector& V) 
{
    if (this != &V)
    {
        delete[]Vec;
        n = V.n;
        Vec = new double[n];
        for (int i = 0; i < n; i++) 
        {
            Vec[i] = V.Vec[i];
        }
    }
    return *this;
}

double& Vector::operator[](int pos) 
{
    return Vec[pos];
}

std::ostream& operator<<(std::ostream& os, Vector& V) 
{
    for (int i = 0; i < V.n; i++)
        os << std::fixed << V.Vec[i] << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& V) 
{
    for (int i = 0; i < V.n; i++)
    {
        std::cout << "[" << i << "] = ";
        is >> V.Vec[i];
    }
    return is;
}

void Vector::InputVector(double* y, double* x, double** a, int n)
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