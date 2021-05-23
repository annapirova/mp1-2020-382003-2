#include <iostream>
#include <cstdlib> 
#include "class.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus"); 
    
    int n = 5;
    Gauss g;
    vector x(n), y(n);
    matrix a(n, n);
    matrix m = a;
    vector l = x;

    cout << "матрица:" << endl;
    g.printmatr(a, n);
    cout << "решение:" << endl;
    g.Result('x', x, n);
    cout << endl;
    g.Result('y', y, n);
    cout << endl;
    g.GaussMethod(a, y, n, x);
    cout << "вектор решения" << endl;
    g.Result('x', x, n);
    cout << endl;
    g.Check(a, x, y, n);
    //g.test(m, l, y, n);

    //matrix acopy = a;
    //vector ycopy = y;
    //vector e = acopy * x - ycopy;
    //int i;
    //double ee = (fabs(e[i]));

    return 0;
}