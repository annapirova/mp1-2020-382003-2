#include <iostream>
#include "Gauss.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "Rus");

    double** a;
    double* y;
    double* x;
    int n = 3;
    int i;

    a = new double* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }
    y = new double[n];
    x = new double[n];

    Gauss InputA, InputV, Multi, Method, Result;
    InputA.InputMatr(a, n);
    cout << endl;
    InputV.InputVector(y, x, a, n);
    cout << endl;
    Result.Result('x', x, n);
    cout << endl;
    Result.Result('y', y, n);
    cout << endl;
    Method.GaussMethod(a, y, n, x);
    Result.Result('x', x, n);

}