#pragma once
#include <iostream>
using namespace std;

class Vector
{
    double* Vec;
    int n;
public:

    Vector(int n);
    Vector(const Vector& V);
    ~Vector();

     Vector operator+(const Vector& V) const;
    Vector operator-(const Vector& V) const;
    Vector operator*(double var);
    friend Vector operator*(double var, const Vector& V);
    Vector& operator+=(const Vector& V);
    Vector& operator-=(const Vector& V);
    Vector& operator=(const Vector& V);
    double& operator[](int pos);
    friend std::ostream& operator<<(std::ostream& os, Vector& V);
    friend std::istream& operator>>(std::istream& is, Vector& V);
    friend class Matrix;
    friend class Gauss;

    void InputVector(double* y, double* x, double** a, int n);
};
