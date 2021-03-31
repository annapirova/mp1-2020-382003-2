#include "Solver.h"
#include <iostream>
#include <cmath>
#define EPS 1e-10

Solver::Solver(const matrix& A, const vector& x, const vector& b)
{
	this->A = A;
	this->x = x;
	this->b = b;
	size = x.GetSize();
}

Solver::Solver()
{
	std::cout << "Enter size: ";
	std::cin >> size;
	matrix A(size, size);
	vector x(size), b(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			std::cout << "A[" << i << "][" << j << "] = ";
			std::cin >> A[i][j];
		}
	for (int i = 0; i < size; i++)
	{
		std::cout << "b[" << i << "] = ";
		std::cin >> b[i];
	}
	this->A = A;
	this->x = x;
	this->b = b;
}

void Solver::Gauss()
{
	double t1, t2, a;
	matrix copyA = A;
	vector copyB = b;

	for (int k = 0; k < size - 1; k++)
	{
		int row = copyA.maxRow(k, k);
		copyA.swap(k, row);
		copyB.swap(k, row);
		t1 = copyA[k][k];

		if (abs(t1) < EPS)
			throw std::exception("inconsistent");

		for (int i = k + 1; i < size; i++)
		{
				t2 = copyA[i][k];
				a = t2 / t1;
				for (int j = 0; j < size; j++)
					copyA[i][j] -= copyA[k][j] * a;
				copyB[i] -= copyB[k] * a;
		}
	}

	for (int i = size - 1; i >= 0; i--)
	{
		double sum = 0.0;
		for (int j = i; j < size; j++)
		{
			sum += copyA[i][j] * x[j];
		}
		x[i] = (copyB[i] - sum) / copyA[i][i];
	}

}

void Solver::PrintM()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
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
	for (int i = 0; i < size; i++)
	{
		std::cout << "x" << i << " = " << x[i] << std::endl;
	}
}

bool Solver::Check()
{
	vector tmp = A * x;
	return tmp == b;
}
