#pragma once
#include <iostream>
using namespace std;

class Matrix
{
    double** A;
    int n, m;

public:
    Matrix(int n, int m);
    Matrix(int size);
    Matrix(const Matrix& B);
    ~Matrix();

   Matrix operator+(const Matrix& B) const;
    Matrix& operator-(const Matrix& B) const;
    Matrix operator*(const Matrix& B) const;
    Matrix operator*(double A) const;
    friend Matrix operator*(double A, const Matrix& B);
    Matrix operator*(double var);
    Matrix operator+=(const Matrix& B);
    Matrix& operator-=(const Matrix& B);
    Matrix& operator=(const Matrix& B);
    double* operator[](int pos);
    friend std::ostream& operator<<(std::ostream& os, Matrix& B);
    friend std::istream& operator>>(std::istream& is, Matrix& B);
    friend class Vector;
    friend class Gauss;
    
    void InputMatr(double** A, int n, int m);
};
