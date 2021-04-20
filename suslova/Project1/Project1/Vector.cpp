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

//void Vector::InputVector(double* y, double* x, double** a, int n)
//{
//	int i, j;
//
//	for (i = 0; i < n; i++)
//	{
//		x[i] = rand() % 10;
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		y[i] = 0;
//		for (j = 0; j < n; j++)
//		{
//			y[i] += a[i][j] * x[j];
//		}
//	}
//}