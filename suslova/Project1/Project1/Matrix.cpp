#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
    A = new double* [n];
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

//void Matrix::InputMatr(double** A, int n, int m)
//{
//    int i, j;
//
//    srand(1000);
//    for (i = 0; i < n; i++) 
//    {
//        for (j = 0; j < n; j++)
//        {
//            A[i][j] = rand() % 10;
//            cout << "  " << A[i][j];
//        }
//        cout << endl;
//    }
//}