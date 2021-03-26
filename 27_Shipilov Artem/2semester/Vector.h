#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>

class Vector {
    double *pVector;
    int size;
public:
    explicit Vector(int _size = 1);
    Vector(const Vector &v);
    Vector(const double *array, int _size);
    ~Vector();
    int getSize() const;
    Vector operator+(const Vector &v);
    Vector operator-(const Vector &v);
    Vector operator*(double var);
    Vector& operator+=(const Vector &v);
    Vector& operator-=(const Vector &v);
    Vector& operator=(const Vector &v);
    double& operator[](int pos);
    friend std::ostream& operator<<(std::ostream& os, Vector &v);
    friend std::istream& operator>>(std::istream& in, Vector &v);
};


#endif 
