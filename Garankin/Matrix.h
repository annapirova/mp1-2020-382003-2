#pragma once
#include "Vector.h"
class Matrix
{
private:
	double** Mat;
	double* Vec;
	int str;
	int column;
public:
	void Print();
	void Input();
	double *operator [](int i);
	Matrix operator +(const Matrix& M2)const;
	Matrix operator *(const Matrix& M2) const;
	Vector operator *(const Vector& V2) const;
	Matrix operator =(const Matrix& M2);
	Matrix(int str, int column);
	Matrix(const Matrix& M2);
	Matrix();
	~Matrix();
};

