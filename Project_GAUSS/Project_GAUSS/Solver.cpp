#include "Solver.h"
#include <iostream>
#include <cmath>


Solver::Solver(const matrix& A, const vector& x, const vector& b)
{
	this->A = A;
	copyA = A;
	this->x = x;
	this->b = b;
	copyb = b;
}

Solver::Solver()
{
	cout << "Введите размер матрицы: ";
	cin >> size;

	if (size < 0) 
	{
	W = ERROR_INSERT_SIZES;
	cout << "SYSTEM DOW{" << W << "}||ERROR_INSERT_SIZE||size<0 " << endl;
	system("pause");
	exit(W);
	}

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
	copyA = A;
	this->x = x;
	this->b = b;
	copyb = b;
}

void Solver::Gauss()
{
	
		for (int k = 0, p = 0; k < copyA.n - 1 && p < copyA.m; k++, p++)
		{
			if (abs(copyA[k][p]) < EPS)
			{
				int max = copyA.maxRow(p, k);
				copyA.swap(k, max);
				copyb.swap(k, max);
			}
			t1 = copyA[k][p];

			for (m = k + 1; m < copyA.n; m++) 
			{
				if (abs(copyA[m][k]) > t1)
				{
					copyA.swap(m, k);
					copyb.swap(m, k);
					t1 = copyA[k][p];
				}
			}

			for (int i = k + 1; i < copyA.n; i++)
			{
				t2 = copyA[i][p];
				a = t2 / t1;
				for (int j = 0; j < copyA.m; j++)
					copyA[i][j] -= copyA[k][j] * a;
				copyb[i] -= copyb[k] * a;
			}
		}

		int k = copyA.n;
		if ((copyA[k-1][k-1] == 0) && (copyb[k-1] != 0))
		{
		W = ERROR_Aij_EQUAL_ZERO_BUT_bij_NOT;
		cout << "SYSTEM DOWN{" << W << "}||ERROR_A[n][n]_EQUAL_ZERO_BUT_b[n][n]_NOT||the system is incompatible" << endl;
		system("pause");
		exit(W);
		}

		if ((copyA[k-1][k-1] == 0) && (copyb[k-1] == 0))
		{
		W = ERROR_Aij_EQUAL_ZERO_AND_bij_EQUAL_ZERO;
		cout << "SYSTEM DOWN{" << W << "}||ERROR_A[n][n]_EQUAL_ZERO_AND_b[n][n]_EQUAL_ZERO||the system the system has free members in the solution" << endl;
		system("pause");

		exit(W);
		}

		for (int i = copyA.n - 1; i >= 0; i--)
		{
			double sum = 0.0;
			for (int j = i; j < copyA.n; j++)
			{
				sum += copyA[i][j] * x[j];
			}
			x[i] = (copyb[i] - sum) / copyA[i][i];
		}

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

void Solver::PrintM(int t)
{
	if (t == 2)
	{
		tA = copyA;
		tb = copyb;
	}
	else
	{
		tA = A;
		tb = b;
	}
	for (int i = 0; i < A.n; i++)
	{
		for (int j = 0; j < A.m; j++)
		{
			std::cout.width(7);
			std::cout.precision(2);
			std::cout << std::fixed << tA[i][j] << " ";
		}
		std::cout.precision(2);
		std::cout << "| " << std::fixed << tb[i] << std::endl;
	}
	std::cout << std::endl;
}

void Solver::PrintX()
{
	for (int i = 0; i < A.n; i++)
	{
		std::cout << "x" << i << " = " << x[i] << std::endl;
	}
}

void Solver::PrintB()//Здесь было изменение относительно вывода, я начал выводить сразу произведение А*х
{
	vector tmp = A * x;
	for (int i = 0; i < A.n; i++)
	{
		std::cout << "b" << i << " = " << tmp[i] << std::endl;
	}
}

void Solver::Check()
{
	vector tmp = A * x;
	if (tmp == b) 
	{
		W = SUCCESS;
		cout << "SYSTEM DOWN{" << W << "}||SUCCESS||" << endl;
	}
	else 
	{
		W = ERROR_ACCURACY_COMPUTING;
		cout << "SYSTEM DOWN{" << W << "}||ERROR_ACCURACY_COMPUTING||when checking, the obtained values exceed the error" << endl;

	}
}