#include "Matrix.h"
#include <iostream>

matrix::matrix(int n, int m)
{
	if (n <= 0 || m <= 0)
		throw std::exception("Rows and colums must be greater than 0 ");

	row = n;
	col = m;
	val = new vector[row];
	for (int i = 0; i < row; i++)
		val[i] = vector(col);
}

matrix::matrix(int n, int m, int max)
{
	if (n <= 0 || m <= 0)
		throw std::exception("Rows and colums must be greater than 0 ");

	row = n;
	col = m;
	val = new vector[row];
	for (int i = 0; i < row; i++)
		val[i] = vector(col, (max - i));
}

matrix::matrix(const matrix& other)
{
	row = other.row;
	col = other.col;
	val = new vector[row];
	for (int i = 0; i < row; i++)
		val[i] = other.val[i];
}

matrix::~matrix()
{
	delete[] val;
}

void matrix::swap(int a, int b)
{
	vector tmp;
	tmp = val[a];
	val[a] = val[b];
	val[b] = tmp;
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
		return *this;
	else
	{
		delete[] val;
		row = other.row;
		col = other.col;
		val = new vector[row];
		for (int i = 0; i < row; i++)
			val[i] = other.val[i];

		return *this;
	}
}

matrix matrix::operator+(const matrix& other) const
{
	if (row != other.row || col != other.col)
		throw std::exception("Wrong sizes");

	matrix res(row, col);

	for (int i = 0; i < row; i++)
		res.val[i] = val[i] + other.val[i];

	return res;
}

matrix matrix::operator-(const matrix& other) const
{
	if (row != other.row || col != other.col)
		throw std::exception("Wrong sizes");

	matrix res(row, col);

	for (int i = 0; i < row; i++)
		res.val[i] = val[i] - other.val[i];

	return res;
}

matrix matrix::operator*(const matrix& other) const
{
	if (col != other.row)
		throw std::exception("Wrong sizes");

	matrix res(row, other.col);

	for (int i = 0; i < res.row; i++)
		for (int j = 0; j < res.col; j++)
		{
			for (int l = 0; l < col; l++)
				res.val[i][j] += val[i][l] * other.val[l][j];
		}
	return res;
}

matrix& matrix::operator+=(const matrix& other)
{
	if (row != other.row || col != other.col)
		throw std::exception("Wrong sizes");

	for (int i = 0; i < row; i++)
		val[i] += other.val[i];

	return *this;
}

matrix& matrix::operator-=(const matrix& other)
{
	if (row != other.row || col != other.col)
		throw std::exception("Wrong sizes");

	for (int i = 0; i < row; i++)
		val[i] -= other.val[i];

	return *this;
}

matrix operator*(const matrix& mat, double p)
{
	matrix res(mat.row, mat.col);
	for (int i = 0; i < res.row; i++)
		res.val[i] = mat.val[i] * p;
	return res;
}

matrix operator*(double p, const matrix& mat)
{
	matrix res(mat.row, mat.col);
	for (int i = 0; i < res.row; i++)
		res.val[i] = mat.val[i] * p;
	return res;
}

std::ostream& operator<<(std::ostream& os, const matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		os << mat.val[i];
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, const matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		std::cout << "[" << i << "]";
		is >> mat.val[i];
	}
	return is;
}

vector& matrix::operator[](int i)
{
	if (i < 0 || i >= row)
		throw std::exception("Wrong row");
	return val[i];
}

const vector& matrix::operator[](int i) const
{
	if (i < 0 || i >= row)
		throw std::exception("Wrong row");
	return val[i];
}

vector operator*(const matrix& M, const vector& v)
{
	if (M.col != v.GetSize())
		throw std::exception("Wrong sizes");

	vector res(M.row);
	for (int i = 0; i < M.row; i++)
	{
		for (int j = 0; j < M.col; j++)
		{
			res[i] += M[i][j] * v[j];
		}
	}
	return res;
}

int matrix::maxRow(int row, int colum)
{
	int maxRow = row;
	double maxElem = abs(val[row][colum]);
	for (int i = row + 1; i < this->row; i++)
		if (abs(val[i][colum]) > maxElem)
		{
			maxElem = abs(val[i][colum]);
			maxRow = i;
		}
	return maxRow;
}

bool matrix::IsSqr() const
{
	return row == col;
}
