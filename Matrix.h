#include <iostream>

class matrix
{
	double** A;
	int n, m;
public:
	matrix();
	matrix(int n, int m);
	matrix(const matrix& other);
	~matrix();

	matrix& operator=(const matrix& other);
	matrix operator+(const matrix& other);
	matrix operator-(const matrix& other);
	matrix operator*(const matrix& other);
	matrix& operator+=(const matrix& other);
	matrix& operator-=(const matrix& other);
	friend matrix operator*(const matrix& other, double p);
	friend matrix operator*(double p, const matrix& other);
	friend std::ostream& operator<<(std::ostream& os, const matrix& mat);
	double* operator[](int i);
	void Gauss();
	friend class Solver;
};