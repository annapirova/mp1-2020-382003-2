#pragma once
#include "Matrix.h"
#include "Vector.h"
class Solver
{
	matrix A;
	vector x, b;
public:
	Solver(const matrix& A, const vector& x, const vector& b);
	Solver();
	void Gauss();
	void PrintM();
	void PrintAns();
	bool Check();
};
