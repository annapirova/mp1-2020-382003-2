#include "Matrix.h"

Matrix::Matrix(int _rows, int _columns): rows(_rows), columns(_columns) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(const Matrix &m): rows(m.rows), columns(m.columns) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::Matrix(double **array, int _rows, int _columns): rows(_rows), columns(_columns) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = array[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete []matrix[i];
    }
    delete []matrix;
}

double Matrix::getValue(int posRow, int posColumn) {
    return matrix[posRow][posColumn];
}

void Matrix::setValue(int posRow, int posColumn, double value) {
    matrix[posRow][posColumn] = value;
}

Matrix Matrix::transposition() const {
    Matrix tmp(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[j][i] = matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator+(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const Matrix &m) {
    assert(columns == m.rows);
    Matrix tmp(rows, m.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            for (int k = 0; k < columns; k++) {
              tmp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return tmp;
}

Matrix Matrix::operator*(double var) {
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = matrix[i][j] * var;
        }
    }
    return tmp;
}

Matrix &Matrix::operator+=(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m) {
    assert(rows == m.rows && columns == m.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] -= m.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(const Matrix &m) {
    if(this != &m)
    {
        for (int i = 0; i < rows; i++) {
            delete []matrix[i];
        }
        delete []matrix;
        rows = m.rows;
        columns = m.columns;
        matrix = new double *[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double [columns];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            os << m.getValue(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& in, Matrix& m) {
    int _rows, _columns;
    std::cin >> _rows;
    std::cin >> _columns;
    double** tmp = new double* [_rows];
    for (int i = 0; i < _rows; i++)
    {
        tmp[i] = new double[_columns];
    }
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _columns; j++)
            std::cin >> tmp[i][j];
    Matrix res(tmp, _rows, _columns);
    m = res;
    for (int i = 0; i < _rows; i++)
        delete[]tmp[i];
    delete[]tmp;
    return in;
}
