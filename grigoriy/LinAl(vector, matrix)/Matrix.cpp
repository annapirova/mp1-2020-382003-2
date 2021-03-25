#include "Matrix.h"

Matrix::Matrix(int _rows, int _columns): rows(_rows), columns(_columns) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 1e-14; //0.0;
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

Matrix::Matrix(const Vector& v, int _rows): rows(_rows), columns(v.getSize()) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = v.pVector[j]; // need private field
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

int Matrix::getNumRows() const {
    return rows;
}

int Matrix::getNumColumns() const {
    return columns;
}

double Matrix::getValue(int posRow, int posColumn) {
    if (posRow < 0 || posRow >= this->getNumRows())
        throw "There is no such row index in the matrix";
    if (posColumn< 0 || posColumn >= this->getNumRows())
        throw "There is no such column index in the matrix";
    return matrix[posRow][posColumn];
}

void Matrix::setValue(int posRow, int posColumn, double value) {
    if (posRow < 0 || posRow >= this->getNumRows())
        throw "There is no such row index in the matrix";
    if (posColumn< 0 || posColumn >= this->getNumRows())
        throw "There is no such column index in the matrix";
    matrix[posRow][posColumn] = value;
}

void Matrix::generateRand() const {
    srand(time(0));
    for (int i = 0; i < this->getNumRows(); ++i) {
        for (int j = 0; j < this->getNumColumns(); ++j) {
            this->matrix[i][j] = (double)rand() / RAND_MAX * 100.0;
        }
    }
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

Matrix Matrix::operator-() {
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = (-1)*matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator+(const Matrix &m) /*const */{
//    assert(rows == m.rows && columns == m.columns);
    if (rows != m.rows)
        throw "The number of matrix rows doesn't match";
    if (columns != m.columns)
        throw "The number of matrix columns doesn't match";
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix &m) {
//    assert(rows == m.rows && columns == m.columns);
    if (rows != m.rows)
        throw "The number of matrix rows doesn't match";
    if (columns != m.columns)
        throw "The number of matrix columns doesn't match";
    Matrix tmp(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tmp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const Matrix &m) {
//    assert(columns == m.rows);
    if (columns != m.rows)
        throw "The number of columns in the first matrix doesn't match the number of rows in the second matrix";
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

Vector Matrix::operator*(const Vector &v) {
//    assert(getNumColumns() == v.getSize());
    if(getNumColumns() != v.getSize())
        throw "The number of columns in the matrix doesn't match the number of elements in the vector";
    Vector res(getNumRows());
    for (int i = 0; i < getNumRows(); ++i) {
        for (int j = 0; j < getNumColumns(); ++j) {
            res.pVector[i] += matrix[i][j] * v.pVector[j];
        }
    }
    return res;
}

Matrix &Matrix::operator+=(const Matrix &m) {
//    assert(rows == m.rows && columns == m.columns);
    if (rows != m.rows)
        throw "The number of matrix rows doesn't match";
    if (columns != m.columns)
        throw "The number of matrix columns doesn't match";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m) {
//    assert(rows == m.rows && columns == m.columns);
    if (rows != m.rows)
        throw "The number of matrix rows doesn't match";
    if (columns != m.columns)
        throw "The number of matrix columns doesn't match";
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

double* Matrix::operator[](int pos) {
    return matrix[pos];
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

std::istream &operator>>(std::istream &is, Matrix &m) {
    int _rows, _columns;
    std::cout << std::endl << "Input number of rows: ";
    std::cin >> _rows;
    std::cout << std::endl << "Input number of columns: ";
    std::cin >> _columns;
    double **tmp = new double *[_rows];
    for (int i = 0; i < _rows; ++i) {
        tmp[i] = new double [_columns];
    }
    for (int i = 0; i < _rows; ++i) {
        std::cout << std::endl << "Input elements of " << i + 1 << " row: ";
        for (int j = 0; j < _columns; ++j) {
            std::cin >> tmp[i][j];
        }
    }
    m = Matrix(tmp, _rows, _columns);
    for (int i = 0; i < _rows; ++i) {
        delete[]tmp[i];
    }
    delete[]tmp;
    return is;
}
