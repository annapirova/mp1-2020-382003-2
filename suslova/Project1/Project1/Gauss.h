#pragma once
#include "Matrix.h"
#include "Vector.h"
using namespace std;

class Gauss
{
    Matrix A;
    Vector y, x;
    int n;

public:

   // void Solver();
    void InputMatr(double** a, int n);
    void InputVectorX(double* y, double* x, double** a, int n);
    void GaussMethod(double** a, double* y, int n, double* x);
    void Result(char c, double* x, int n);
};
