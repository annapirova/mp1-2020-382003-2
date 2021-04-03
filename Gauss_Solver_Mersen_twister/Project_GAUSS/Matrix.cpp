#include "Matrix.h"

void matrix::RANDOM(int argc, double** A)
{
	unsigned int time_ui = unsigned int(time(NULL));
		MersenneTwisterGENERATOR* NumberGenerator;
		NumberGenerator = MersenneTwisterGENERATOR::getInstance();
		NumberGenerator->changeSeed(time_ui);
		if (NULL == NumberGenerator)
		{
			W = ERROR_NUMBER_GEN;
			cout << "SYSTEM DOW{" << W << "}||ERROR_NUMBER_GEN_MATRIX||" << endl;
			system("pause");
			exit(W);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = NumberGenerator->getFloat();
		term();
}

void matrix::term()
{
	MersenneTwisterGENERATOR* NumberGenerator = MersenneTwisterGENERATOR::getInstance();
	if (NULL != NumberGenerator)
	{
		// destroy singleton object
		NumberGenerator->release();
		NumberGenerator = NULL;
	}
}

matrix::matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	A = new double*[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = 0.0;
}

matrix::matrix(int R, int L, int max)
{
	srand((unsigned int)time(NULL));
	n = R;
	m = L;
	A = new double*[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	RANDOM(n, A);
}

matrix::matrix(const matrix& other)
{
	n = other.n;
	m = other.m;
	A = new double*[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = other.A[i][j];
}

matrix::~matrix()
{
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}

int matrix::maxRow(int colum, int row)
{
	for (int i = row; i < n; i++)
	{
		if (abs(A[i][colum]) > EPS)
		{
			return i;
		}
	}
	return 0;
}

void matrix::swap(int a, int b)
{
	double temp = 0.0;
	for (int i = 0; i < n; i++)
	{
		temp = A[a][i];
		A[a][i] = A[b][i];
		A[b][i] = temp;
	}
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
		return *this;
	else
	{
		for (int i = 0; i < n; i++)
			delete[] A[i];
		delete[] A;
		n = other.n;
		m = other.m;
		A = new double*[n];
		for (int i = 0; i < n; i++)
			A[i] = new double[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = other.A[i][j];

		return *this;
	}
}

matrix matrix::operator+(const matrix& other) const
{
	matrix res(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.A[i][j] = A[i][j] + other.A[i][j];

	return res;
}

matrix matrix::operator-(const matrix& other) const
{
	matrix res(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.A[i][j] = A[i][j] - other.A[i][j];

	return res;
}

matrix matrix::operator*(const matrix& other) const
{
	matrix res(n, other.m);

	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
		{
			for (int l = 0; l < m; l++)
				res.A[i][j] += A[i][l] * other.A[l][j];
		}
	return res;
}

matrix& matrix::operator+=(const matrix& other)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] += other.A[i][j];

	return *this;
}

matrix& matrix::operator-=(const matrix& other)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] -= other.A[i][j];

	return *this;
}

matrix operator*(const matrix& other, double p)
{
	matrix res(other.n, other.m);
	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
			res.A[i][j] = other.A[i][j] * p;
	return res;
}

matrix operator*(double p, const matrix& other)
{
	matrix res(other.n, other.m);
	for (int i = 0; i < res.n; i++)
		for (int j = 0; j < res.m; j++)
			res.A[i][j] = p * other.A[i][j];
	return res;
}

std::ostream& operator<<(std::ostream& os, const matrix& m)
{
	os.width(7);
	os.precision(2);
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			os << std::fixed << m.A[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator >> (std::istream& is, const matrix& m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.m; j++)
		{
			std::cout << "[" << i << "][" << j << "] = ";
			is >> m.A[i][j];
		}
	}
	return is;
}

double* matrix::operator[](int i)
{
	if (i >= 0 && i < m)
		return A[i];
	else
		return A[0];
}

const double* matrix::operator[](int i) const
{
	if (i >= 0 && i < n)
		return A[i];
	else
		return A[0];
}