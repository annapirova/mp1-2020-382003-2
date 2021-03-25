#include "Vector.h"

Vector::Vector(int _size) {
    size = _size;
    pVector = new double [size];
    for (int i = 0; i < size; i++)
        pVector[i] = 1e-14; //0.0;
}

Vector::Vector(const Vector &v) {
    size = v.size;
    pVector = new double [size];
    for (int i = 0; i < size; i++)
        pVector[i] = v.pVector[i];
}

Vector::Vector(const double *array, int _size) {
    size = _size;
    pVector = new double[size];
    for (int i = 0; i < size; i++) {
        pVector[i] = array[i];
    }
}

Vector::~Vector() {
    delete []pVector;
}

int Vector::getSize() const {
    return size;
}

double Vector::getValue(int pos) {
    if (pos < 0 || pos >= this->getSize())
        throw "There is no such index in the vector";
    return pVector[pos];
}

void Vector::setValue(int pos, double value) {
    if (pos < 0 || pos >= this->getSize())
        throw "There is no such index in the vector";
    pVector[pos] = value;
}

void Vector::generateRand() const {
    for (int i = 0; i < this->getSize(); ++i) {
        this->pVector[i] = (double)rand() / RAND_MAX * 100.0;
    }
}


Vector Vector::operator-() {
    Vector tmp(size);
    for (int i = 0; i < size; i++) {
        tmp.pVector[i] = (-1)*pVector[i];
    }
    return tmp;
}

Vector Vector::operator+(const Vector &v) {
//    assert(size == v.size);
    if (size != v.size)
        throw "The number of vector elements doesn't match";
    Vector tmp(size);
    for (int i = 0; i < size; i++) {
        tmp.pVector[i] = pVector[i] + v.pVector[i];
    }
    return tmp;
}

Vector Vector::operator-(const Vector &v) {
//    assert(size == v.size);
    if (size != v.size)
        throw "The number of vector elements doesn't match";
    Vector tmp(size);
    for (int i = 0; i < size; i++) {
        tmp.pVector[i] = pVector[i] - v.pVector[i];
    }
    return tmp;
}

Vector Vector::operator*(double var) {
    Vector tmp(size);
    for (int i = 0; i < size; i++) {
        tmp.pVector[i] = pVector[i] * var;
    }
    return tmp;
}

Vector &Vector::operator+=(const Vector &v) {
//    assert(size == v.size);
    if (size != v.size)
        throw "The number of vector elements doesn't match";
    for (int i = 0; i < size; i++) {
        pVector[i] += v.pVector[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &v) {
//    assert(size == v.size);
    if (size != v.size)
        throw "The number of vector elements doesn't match";
    for (int i = 0; i < size; i++) {
        pVector[i] -= v.pVector[i];
    }
    return *this;
}

Vector &Vector::operator=(const Vector &v) {
    if (this != &v)
    {
        delete []pVector;
        size = v.size;
        pVector = new double[size];
        for (int i = 0; i < size; i++) {
            pVector[i] = v.pVector[i];
        }
    }
    return *this;
}

double &Vector::operator[](int pos) {
    return pVector[pos];
}

std::ostream &operator<<(std::ostream &os, Vector &v) {
    for (int i = 0; i < v.size; i++) {
        os << v.pVector[i] << " ";
    }
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Vector &v) {
    int _size;
    std::cout << std::endl << "Input size of vector: ";
    std::cin >> _size;
    std::cout << std::endl << "Input elements of vector: ";
    double *arrayForVector = new double [_size];
    for (int i = 0; i < _size; ++i) {
        std::cin >> arrayForVector[i];
    }
    Vector tmp(arrayForVector, _size);
    v = tmp;
    delete[]arrayForVector;
    return is;
}
