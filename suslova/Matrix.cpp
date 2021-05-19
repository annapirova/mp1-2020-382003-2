#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int n, int m)
{
    A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }
}

Matrix::Matrix(int size)
{
    n = size;
    m = size;

    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }
}

Matrix::Matrix(const Matrix& B)
{
    n = B.n;
    m = B.m;

    A = new double* [n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[]A;
}

Matrix Matrix::operator+(const Matrix& B) const 
{
    Matrix result(n, m);

    for (int i = 0; i < n; i++)
        result.A[i] = A[i] + B.A[i];

    return result;
}

Matrix& Matrix::operator-(const Matrix& B) const 
{
    Matrix result(n, m);

    for (int i = 0; i < n; i++)
        result.A[i] = A[i] - B.A[i];

    return result;
}

Matrix Matrix::operator*(const Matrix& B) const 
{
    Matrix result(n, B.m);

    for (int i = 0; i < result.n; i++)
        for (int j = 0; j < result.m; j++)
        {
            for (int l = 0; l < m; l++)
                result.A[i][j] = A[i][l] + A[i][l] * B.A[l][j];
        }
    return result;
}

Matrix Matrix::operator*(double var) 
{
    Matrix result(n, m);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            result.A[i][j] = A[i][j] * var;
        }
    }
    return result;
}

Matrix Matrix::operator+=(const Matrix& B) 
{
    Matrix result(n, m);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            A[i][j] += B.A[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& B) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            A[i][j] -= B.A[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& B)
{
    if (this != &B)
    {
        for (int i = 0; i < n; i++) 
        {
            delete[]A[i];
        }
        delete[]A;

        n = B.n;
        m = B.m;
        A = new double* [n];
        for (int i = 0; i < n; i++) 
        {
            A[i] = new double[n];
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                A[i][j] = B.A[i][j];
            }
        }
    }
    return *this;
}

double* Matrix::operator[](int pos) 
{
    return A[pos];
}

std::ostream& operator<<(std::ostream& os, Matrix& B)
{
    for (int i = 0; i < B.n; i++)
    {
        os << B.A[i];
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& B)
{
    for (int i = 0; i < B.n; i++)
    {
        std::cout << "[" << i << "]";
        is >> B.A[i];
    }
    return is;
}

void Matrix::InputMatr(double** A, int n, int m)
{
    int i, j;

    srand(1000);
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;
            cout << "  " << A[i][j];
        }
        cout << endl;
    }
}
