#include <locale>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Matrix 
{
	int n;
	double** B; double* A;

public:
	Matrix(int N);
	void insert();
	void print();
	void gaus();
	void exit();
	void random();
	~Matrix()
	{
		delete[] B;
	}
};



void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите размер" << endl;
	cin >> n;

	Matrix mat(n);
	mat.insert();
	mat.print();
	mat.gaus();
	mat.print();
	mat.exit();
	cin >> n;
}

Matrix::Matrix()
{
	n = 4;
	B = (double**) new double*[n];
	for (int i = 0; i < n + 1; i++)
	{
		B[i] = (double*) new double[n + 1];
	}
	A = (double*)new double[n];
}

Matrix::Matrix(int N)
{
	n = N;
	B = (double**) new double*[n];
	for (int i = 0; i < n + 1; i++)
	{
		B[i] = (double*) new double[n];
	}
	A = (double*)new double[n];

}

void Matrix::insert()
{
	int i, j;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << "B[i][j]=";
			cin >> B[i][j];
}

void Matrix::print()
{
	cout << "matrix:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << B[i][j] << "  ";
		}
		cout << endl;
	}
}

void Matrix::gaus()
{
	for (k = 0; k<n; k++) 
	{
		aa = abs(B[k][k]);
		i = k;
		for (m = k + 1; m<n; m++)
			if (abs(B[m][k])>aa)
			{
				i = m;
				aa = abs(a[m][k]);
			}

		if (aa == 0)  
		{
			cout << "—истема не имеет решений" << endl;
		}

		if (i != k)  
		{
			for (j = k; j < n + 1; j++)
			{
				bb = B[k][j];
				B[k][j] = B[i][j];
				B[i][j] = bb;
			}
		}
		aa = B[k][k];
		B[k][k] = 1;
		for (j = k + 1; j<n + 1; j++)
			if (aa != 0) {
				B[k][j] = B[k][j] / aa;
			}
		for (i = k + 1; i < n; i++)
		{
			bb = B[i][k];
			B[i][k] = 0;
			if (bb != 0)
				for (j = k + 1; j< n + 1; j++)
					B[i][j] = B[i][j] - bb*B[k][j];
		}
	}

	for (i = n - 1; i >= 0; i--)   
	{
		A[i] = 0;
		aa = B[i][n];
		for (j = n; j>i; j--)
			aa = aa - B[i][j] * A[j];
		A[i] = aa;
	}
}

void Matrix::exit()
{
	cout << "–ешение системы:" << endl;  //ответ
	for (int i = 0; i< n; i++)
	{
		cout << "x[" << i << "]=" << A[i] << endl;
	}
}