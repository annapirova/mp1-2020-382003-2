#pragma once
using namespace std;

class Matrix
{
    double** A;
    int n, m;

public:

    Matrix(int n, int m);
    Matrix(const Matrix& B);
    ~Matrix();

    //void InputMatr(double** A, int n, int m);
};