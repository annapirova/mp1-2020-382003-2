#include "Matrix.h"
#include "Vector.h"
#include <iostream>

using namespace std;


void Matrix::Print()
{
	cout << "¬аша матрица: ";
	for (int i = 0; i < str; i++)
	{
		cout << "|";
		for (int j = 0; j < column; j++)
		{
			cout<< Mat[i][j]<<"\t";
		}
		cout << "|\n";
	}
}


void Matrix::Input()
{
	cout << "¬ведите элементы матрицы: ";
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> Mat[i][j];
		}
	}
}


Matrix:: Matrix()
{
	this->str = 10;
	this->column = 10;
	this->Mat = new double* [str];
	for (int i = 0; i < column; i++)
	{
		this->Mat[i] = new double[column];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < column; j++)
		{
			Mat[i] = 0;
		}
	}
}


Matrix:: Matrix(int str, int column)
{
	this->Mat = new double* [str];
	for (int i = 0; i < column; i++)
	{
		this->Mat[i] = new double [column];
	}
}


Matrix::Matrix(const Matrix& other)
{
	this->str = other.str;
	this->column = other.column;
	this->Mat = new double* [str];
	for (int i = 0; i < column; i++)
	{
		this->Mat[i] = new double [column];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < column; j++)
		{
			this->Mat[i][j] = other.Mat[i][j];
		}
	}
}


double* Matrix:: operator [](int i)
{
	return Mat[i];
}


Matrix Matrix:: operator =(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}
	if (this->str != other.str)
	{
		delete[] Mat;
		this->Mat = new double* [other.str];
		this->str = other.str;
	}
	if (this->column != other.column)
	{
		delete[] Mat;
		this->Mat = new double* [other.column];
		this->column = other.column;
	}
	for (int i = 0; i < other.str; i++)
	{
		for (int j = 0; j < other.column; j++)
		{
			this->Mat[i][j] = other.Mat[i][j];
		}
	}
	return *this;
}


Matrix Matrix:: operator +(const Matrix& other) const
{
	Matrix T(other.str, other.column);
	for (int i = 0; i < other.str; i++)
	{
		for (int j = 0; j < other.column;j++)
		{
			T.Mat[i][j] = this-> Mat[i][j] + other.Mat[i][j];
		}
	}
	return T;
}


Matrix Matrix:: operator *(const Matrix& other) const
{
	Matrix T(other.str, other.column);
	for (int i = 0; i < other.str; i++)
	{
		for (int j = 0; j < other.column; j++)
		{
			T.Mat[i][j] = this->Mat[i][j] * other.Mat[j][i];
		}
	}
	return T;
}


Vector Matrix:: operator *(const Vector& other) const
{
	Vector T;
	//Matrix T(this->str, this->column);
	for (int i = 0; i < this->str; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			T.Vec[i] += this->Mat[i][j] * other.Vec[j];
		}
	}
	return T;
}

Matrix:: ~Matrix()
{
	for (int i = 0; i < str; i++)
	{
		delete Mat[i];
	}
	delete[] Mat;
}
