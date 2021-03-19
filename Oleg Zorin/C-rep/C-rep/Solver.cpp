#include "Solver.h"
#include <iostream>
#include <cmath>
#define EPS 1e-10

Solver::Solver(const matrix& A, const vector& x, const vector& b)
{
	this->A = A;
	this->x = x;
	this->b = b;
}

Solver::Solver()
{
	int size = 0;
	std::cout << "Enter size: ";
	std::cin >> size;
	matrix A(size, size);
	vector x(size), b(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			std::cout << "A[" << i << "][" << j << "] = ";
			std::cin >> A.A[i][j];
		}
	for (int i = 0; i < size; i++)
	{
		std::cout << "b[" << i << "] = ";
		std::cin >> b.value[i];
	}
	this->A = A;
	this->x = x;
	this->b = b;
}

vector operator*(const matrix& M, const vector& v)
{
	int size = v.GetSize();
	vector res(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i] += M[i][j] * v[j];
		}
	}
	return res;
}

void Solver::Gauss()
{
	double t1, t2, a;
	matrix copyA = A;
	vector copyB = b;

	for (int k = 0, p = 0; k < copyA.n - 1 && p < copyA.m; k++, p++)
	{
		if (fabs(copyA[k][p]) < EPS)
		{
			copyA.swap(k, k + 1);
			copyB.swap(k, k + 1);
		}
		t1 = copyA[k][p];

		for (int i = k + 1; i < copyA.n; i++)
		{
				t2 = copyA[i][p];
				a = t2 / t1;
				for (int j = 0; j < copyA.m; j++)
					copyA[i][j] -= copyA[k][j] * a;
				copyB[i] -= copyB[k] * a;
		}
	}

	for (int i = copyA.n - 1; i >= 0; i--)
	{
		double sum = 0.0;
		for (int j = i; j < copyA.n; j++)
		{
			sum += copyA[i][j] * x[j];
		}
		x[i] = (copyB[i] - sum) / copyA[i][i];
	}

}

void Solver::PrintM()
{
	for (int i = 0; i < A.n; i++)
	{
		for (int j = 0; j < A.m; j++) 
		{
			std::cout.width(7);
			std::cout.precision(2);
			std::cout << std::fixed << A[i][j] << " ";
		}
		std::cout.precision(2);
		std::cout << "| " << std::fixed << b[i] << std::endl;
	}
	std::cout << std::endl;
}

void Solver::PrintAns()
{
	for (int i = 0; i < A.n; i++)
	{
		std::cout << "x" << i << " = " << x[i] << std::endl;
	}
}

bool Solver::Check()
{
	vector tmp = A * x;
	return tmp == b;
}
