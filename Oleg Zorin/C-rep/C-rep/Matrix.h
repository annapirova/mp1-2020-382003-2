#pragma once
#include <iostream>

class matrix
{
	vector* val;
	int row, col;
public:
	matrix(int n = 1, int m = 1);
	matrix(int n, int m, int max);
	matrix(const matrix& other);
	~matrix();

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
	friend std::istream& operator>>(std::istream& is, const matrix& mat);
	vector& operator[](int i);
	const vector& operator[](int i) const;
	int maxRow(int row, int colum) const;
	friend vector operator*(const matrix& M, const vector& v);
};