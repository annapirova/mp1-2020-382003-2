#ifndef LINAL_VECTOR__MATRIX__VECTOR_H
#define LINAL_VECTOR__MATRIX__VECTOR_H

#include <iostream>
#include <cassert>

class Vector {
//public:
    double *pVector;
    int size;
public:
    explicit Vector(int _size = 1);
    Vector(const Vector &v);
    Vector(const double *array, int _size);
    ~Vector();
    int getSize() const;
    double getValue(int pos);
    void setValue(int pos, double value);
    void generateRand() const;
    Vector operator-(); //отрицание
    Vector operator+(const Vector &v);
    Vector operator-(const Vector &v);
    Vector operator*(double var);
    Vector& operator+=(const Vector &v);
    Vector& operator-=(const Vector &v);
    Vector& operator=(const Vector &v);
    double& operator[](int pos);
    friend std::ostream& operator<<(std::ostream& os, Vector &v);
    friend std::istream& operator>>(std::istream& is, Vector &v);
    friend class Matrix;
    friend class Solver;
};


#endif //LINAL_VECTOR__MATRIX__VECTOR_H
