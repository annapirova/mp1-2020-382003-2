#include "Header.h" 

Matrix::Matrix()
{
	n = 4;
	A = (double**) new double*[n];
	B = (double**) new double*[n];
	for (int i = 0; i < n + 1; i++)
	{
		A[i] = (double*) new double[n + 1];
		B[i] = (double*) new double[n + 1];
	}
	x = (double*) new double[n];
	b = (double*) new double[n];
}

Matrix::Matrix(int N)
{
	n = N;
	A = (double**) new double*[n];
	B = (double**) new double*[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = (double*) new double[n+1];
		B[i] = (double*) new double[n+1];
	}
	x =  new double[n];
	b =  new double[n];

	for (int i = 0; i < n; i++) {
		x[i] = 0.0;
		b[i] = 0.0;
		for (int j = 0; j < n + 1; j++) {
			A[i][j] = 0.0;
			B[i][j] = 0.0;
		}
	}
}

void Matrix::insert()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++) {
			cin >> A[i][j];
			B[i][j] = A[i][j];
		}
}

void Matrix::gaus()
{
	for (k = 0; k<n; k++)
	{
		aa = abs(A[k][k]);
		i = k;
		for (m = k + 1; m<n; m++)
			if (abs(A[m][k])>aa)
			{
				i = m;
				aa = abs(A[m][k]);
			}

		if (aa == 0)
		{
			cout << "Система не имеет решений" << endl;
		}

		if (i != k)
		{
			for (j = k; j < n + 1; j++)
			{
				bb = A[k][j];
				A[k][j] = A[i][j];
				A[i][j] = bb;
			}
		}
		aa = A[k][k];
		A[k][k] = 1;
		for (j = k + 1; j<n + 1; j++)
			if (aa != 0) {
				A[k][j] = A[k][j] / aa;
			}
		for (i = k + 1; i < n; i++)
		{
			bb = A[i][k];
			A[i][k] = 0;
			if (bb != 0)
				for (j = k + 1; j< n + 1; j++)
					A[i][j] = A[i][j] - bb*A[k][j];
		}
	}

	for (i = n - 1; i >= 0; i--)
	{
		x[i] = 0;
		aa = A[i][n];
		for (j = n; j>i; j--)
			aa = aa - A[i][j] * x[j];
		x[i] = aa;
	}
}

void Matrix::exit()
{
	cout << "Решение системы:" << endl; //вывод решений
	for (int i = 0; i< n; i++)
	{
		cout << "x[" << i << "]=" << x[i];
		cout << endl;
	}
}

void Matrix::proverka()
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			b[i] =b[i]+ B[i][j] * x[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout <<"\n"<<"b["<<i<<"]"<<"="<< b[i];
	}
}

void Matrix::random(int m)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++) {
			A[i][j] = rand() % (m);
			B[i][j] = A[i][j];
		}
}

void Matrix::PRINT()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout.width(7);
			std::cout.precision(2);
			std::cout << std::fixed << A[i][j] << " ";
		}
		std::cout.precision(2);
		std::cout << "| " << std::fixed << A[i][n] << std::endl;
	}
	std::cout << std::endl;
}