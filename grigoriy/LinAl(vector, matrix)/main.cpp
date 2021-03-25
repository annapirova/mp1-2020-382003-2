#include "Vector.h"
#include "Matrix.h"
#include "Solver.h"
using namespace std;

int main() {
    try{
/*
    double a[10] = {1,2,3,4,5,6,7,8,9,10};
    Vector v1(100), v2(a, 10), v3 = -v2, v4(v3), vv;
    cout << v4.getValue(3) << endl;
    v4.setValue(3, 1024);
    cout << v4.getValue(3) << endl;
    cout << v1.getSize() << endl;
    v4[3] = 512;
    cout << v4[3] << endl;
    for (int i = 0; i < v2.getSize(); i++) {
        cout << v3[i] << endl;
    }

    vv = v4 - v3;
    cout << vv << endl;
    vv = v2 * 11 + v3;
    cout << vv << endl;

    int nr = 3;
    int nc = 4;
    double** a = new double *[nr];
    for (int i = 0; i < nr; ++i) {
        a[i] = new double [nc];
    }
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; ++j) {
            a[i][j] = (i + j + 1) * 10 -(i * j);
        //    cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    cout << endl;

    Matrix m1(a, nr, nc), m2 = m1.transposition(), m3 = -m2, m4 = m1 * m3, m5 = m4 * (-1);
    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nr; ++j) {
            cout << m2.getValue(i, j) << " ";
        }
        cout << endl;
    }
    cout << "####" << endl << m3;
    cout << endl << "####" << endl << m5;
    m3 -= m2;
    m3 = m3 * (-1);
    m5 = m3;
    cout << endl << "####" << endl << m3;
    cout << endl << "####" << endl << m5;

    Matrix mm = m3 + m2;
    cout << m3 << endl << endl << m2 << endl << endl << mm;

    int n = 5;
    int m = 7;
    double **a = new double*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double [m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j-1] = j;
            cout << a[i][j-1] << " ";
        }
        cout << endl;
    }
    Matrix A(a, n, m);
    double aa[] = {1, 2, 3,4,5,6,7};
    Vector x(aa, m), b = A * x;
    cout << endl << b;

    Vector a;
    cout << endl << a;
    cin >> a;
    cout << "hi" << endl;
    cout << a;
    Matrix a;
    cout << endl << a;
    cin >> a;
    cout << "hi" << endl;
    cout << a;
*/

    int n = 3;
    double **matrix = new double* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double [n];
    }
    double *vector = new double [n];
    double *xV = new double [n];
    matrix[0][0] = 2;
    matrix[0][1] = 3;
    matrix[0][2] = 5;
    matrix[1][0] = 3;
    matrix[1][1] = 5;
    matrix[1][2] = 2;
    matrix[2][0] = 5;
    matrix[2][1] = 2;
    matrix[2][2] = 3;
    vector[0] = 38;
    vector[1] = 31;
    vector[2] = 31;
    xV[0] = 2;
    xV[1] = 3;
    xV[2] = 5;


        Solver s;
        Matrix A(matrix, n, n);
        Vector b(vector, n), x(xV, n);
//        s.input();
        s.generate();
        Vector res = s.solve();//(&A, &b, &x);
        cout << endl << "###SOLVER###" << endl << res;
        cout << endl << "###CHECKER###" << endl << s.check();
    }
    catch (const char* exception) {
        cerr << exception;
    }

    return 0;
}
