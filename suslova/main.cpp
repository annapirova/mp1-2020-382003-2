#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Gauss.h"
using namespace std;

void main()
{
    Matrix A(5, 5);
    Vector x(5), y(5);
    Gauss g(A, x, y);
    int n = 5;

    g.InputMatr(A, n);
    cout << endl;
    g.InputVectorX(y, x, A, n);
    cout << endl;
    g.Result('x', x, n);
    cout << endl;
    g.Result('y', y, n);
    cout << endl;
    g.GaussMethod(A, y, n, x);
    g.Result('x', x, n);
}