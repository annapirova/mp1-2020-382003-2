#pragma once
using namespace std;

class Vector
{
    double* Vec;
    int n;
public:

    Vector(int n);
    Vector(const Vector& V);
    ~Vector();

    void InputVector(double* y, double* x, double** a, int n);
};
