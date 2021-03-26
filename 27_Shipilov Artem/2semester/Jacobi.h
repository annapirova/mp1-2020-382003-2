#ifndef JACOBI_H
#define JACOBI_H

#include "Matrix.h"

class Jacobi {
	Matrix A;
	Vector F, X;
public:

	Vector Jacobin();

	void Input();

	void Print();
};

#endif