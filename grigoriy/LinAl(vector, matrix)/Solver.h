#ifndef LINAL_VECTOR__MATRIX__SOLVER_H
#define LINAL_VECTOR__MATRIX__SOLVER_H

#include "Matrix.h"

class Solver {
//public:
    Matrix A;
    Vector b, x, y;
public:
    Vector solve(const Matrix* _A = nullptr, const Vector* _b = nullptr, const Vector* _x = nullptr);
    double check();
    void generate();
    void input();
    void print();
};


#endif //LINAL_VECTOR__MATRIX__SOLVER_H
