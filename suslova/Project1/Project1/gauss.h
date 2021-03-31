#pragma once

#include <iostream>
using namespace std;

class Gauss
{

public:

    void InputMatr(double** a, int n);
    void InputVectorX(double* y, double* x, double** a, int n);
    void GaussMethod(double** a, double* y, int n, double* x);
    void Result(char c, double* x, int n);
};