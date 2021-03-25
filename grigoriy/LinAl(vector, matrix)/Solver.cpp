#include "Solver.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
void SWAP(double &x1, double &x2){double s = x1; x1 = x2; x2 = s;}

void Solver::generate() {
    srand(time(0));
    int orderOfMatrix;
    std::cout << "Enter the order of matrix A: ";
    std::cin >> orderOfMatrix;
    A = Matrix(orderOfMatrix,orderOfMatrix);
    A.generateRand();
    x = Vector(orderOfMatrix);
    x.generateRand();
    b = A * x;
}

void Solver::input() {
    std::cin >> A;
    std::cin >> b;
}

void Solver::print() {
    std::cout << A << std::endl;
    std::cout << x << std::endl;
    std::cout << b << std::endl;
}

Vector Solver::solve(const Matrix *_A, const Vector *_b, const Vector *_x) {
    Matrix AA(A);
    Vector bb(b), yy(A.getNumColumns());
    y = yy;
    if (_A != nullptr)
       AA = *_A;
    if (_b != nullptr)
       bb = *_b;
    if (_x != nullptr)
        x = *_x;
//    assert(AA.getNumRows() == AA.getNumColumns());
    if(AA.getNumRows() != AA.getNumColumns())
        throw "The matrix isn't square";
//    assert(AA.getNumRows() == bb.getSize());
    if (AA.getNumRows() != bb.getSize())
        throw "The number of rows in the matrix doesn't match the number of elements in the vector";
    bool zeroRow = false;
    int countForZeroRow = 0;
/*
    std::cout << "##BEFORE##" << std::endl;
    std::cout << "A: " << std::endl << AA << std::endl;
    std::cout << "b: " << bb << std::endl;
    std::cout << "x: " << x << std::endl;
*/
    // DIRECT
    for (int i = 0; i < AA.getNumRows(); ++i) {
        for (int j = 0; j < AA.getNumColumns(); ++j) {
            if(AA.matrix[i][j] < 1e-18) // Проверка на нулевую строку
            {
                countForZeroRow++;
            }
        }
        if (countForZeroRow == AA.getNumColumns())
        {
            zeroRow = true;
        }
//        assert(!zeroRow || fabs(bb.pVector[i]) > 1e-18); // Бескончено много решений
        if (zeroRow)
        {
            if(fabs(bb.pVector[i]) < 1e-18)
                throw "The system has infinitely many solutions";
            else
                throw "The system has no solutions";
        }
//        assert(!zeroRow); // Нет решений
        for (int j = i + 1; j < AA.getNumRows(); ++j) {
            if(fabs(AA.matrix[i][i]) < fabs(AA.matrix[j][i])){
                for (int k = 0; k < AA.getNumColumns(); ++k) {
                    SWAP(AA.matrix[j][k], AA.matrix[i][k]);
                }
                SWAP(bb.pVector[j], bb.pVector[i]);
            }
//            assert(fabs(AA.matrix[i][i]) > 1e-14);     // divided by ZERO
            if(fabs(AA.matrix[i][i]) < 1e-14)
                throw "Division by zero";
            double coefficient = AA.matrix[j][i] / AA.matrix[i][i];
            for (int k = 0; k < AA.getNumColumns(); ++k) {
                AA.matrix[j][k] -= coefficient * AA.matrix[i][k];
            }
            bb.pVector[j] -= coefficient * bb.pVector[i];
        }
    }

    // REVERSE
    y.pVector[AA.getNumColumns() - 1] = bb.pVector[AA.getNumRows() - 1] / AA.matrix[AA.getNumRows() - 1][AA.getNumColumns() - 1];
    for (int i = AA.getNumRows() - 2; i > -1; i--) {
        double s = 0.0;
        for (int j = i + 1; j < AA.getNumColumns() ; j++) {
            s += AA.matrix[i][j]*y.pVector[j];
        }
        y.pVector[i] = (bb.pVector[i] - s) / AA.matrix[i][i];
    }
/*
    std::cout << "##AFTER##" << std::endl;
    std::cout << "A: " << std::endl << AA << std::endl;
    std::cout << "b: " << bb << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "###CHECK###" << std::endl;
    Vector check_res = y - x;
    std::cout << "check: " << check_res << std::endl;
*/
    return y;
}

double Solver::check() {
    double delta = fabs(y.pVector[0]) - fabs(x.pVector[0]);
    for (int i = 1; i < y.getSize(); ++i) {
        delta = (delta > ( fabs(y.pVector[i]) - fabs(x.pVector[i]))) ? delta : fabs(y.pVector[i]) - fabs(x.pVector[i]);
    }
    return delta;
}
