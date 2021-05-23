#pragma once
#include <iostream>

class vector
{
    double* a;
    int size;
public:
    vector(int n);
    vector(const vector& vec);
    ~vector();
    double& operator[](int i);
    const double& operator[](int i) const;
    vector& operator=(const vector& vec);
    vector operator+(const vector& vec) const;
    vector operator-(const vector& vec) const;
    vector operator*(const vector& vec) const;
    vector& operator+=(const vector& vec);
    vector& operator-=(const vector& vec);
    bool operator==(const vector& vec);
    int GetSize() const;
};

class matrix
{
    double** a;
    int n, m;
public:
    matrix(int n1, int m1);
    matrix(const matrix& mat);
    ~matrix();
    double* operator[](int i);
    //const double& operator[](int i, int j) const;
    //double& getVal(int i, int j) { return a[i]; };
    matrix& operator=(const matrix& mat);
    matrix operator+(const matrix& mat) const;
    matrix operator-(const matrix& mat) const;
    matrix operator*(const matrix& mat) const;
    matrix& operator+=(const matrix& mat);
    matrix& operator-=(const matrix& mat);
    bool operator==(const vector& v) const;
};

class Gauss
{
    int n;
    int num(int i, int j, int n);
public:
    void genarr(double** a, int n);
    void printmatr(matrix& a, int n);
    void GaussMethod(matrix a, vector& y, int n, vector& x);
    void Result(char c, vector& x, int n);
    void Check(matrix a, vector& b, vector& c, int n);
    void test(matrix& a, vector& b, vector& r, int n);
};