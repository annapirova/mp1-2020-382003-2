#pragma once
#include "Vector.h"

class matrix
{
	double** A;
	int n, m;
public:
	matrix(int n = 1, int m = 1);
	matrix(int N,int M ,int max);
	matrix(const matrix& other);
	~matrix();
	int maxRow(int colum, int row);
	void swap(int a, int b);
	matrix& operator=(const matrix& other);
	matrix operator+(const matrix& other) const;
	matrix operator-(const matrix& other) const;
	matrix operator*(const matrix& other) const;
	matrix& operator+=(const matrix& other);
	matrix& operator-=(const matrix& other);
	friend matrix operator*(const matrix& other, double p);
	friend matrix operator*(double p, const matrix& other);
	friend std::ostream& operator<<(std::ostream& os, const matrix& mat);
	friend std::istream& operator >> (std::istream& is, const matrix& mat);
	double* operator[](int i);
	const double* operator[](int i) const;
	friend class Solver;
}; 
