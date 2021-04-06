#pragma once

#include"Vector.h"

class Matrix
{
  int rand_max;
  
  myVector* matr,*matr_solution;//A
  myVector X,b,_solve;
  int size;
  void generate();//рандом
  void hand_init();//Вручную
public:
  Matrix(int n, int rand_max);
  Matrix(const Matrix& m2);
  void init();//Выбор генерации
  double& operator()(int i, int j);
  Matrix& operator=(const Matrix& m2);
  Matrix& operator+=(const Matrix& m2);
  Matrix& operator-=(const Matrix& m2);
  Matrix operator+(const Matrix& m2);
  Matrix operator-(const Matrix& m2);
  void change_str(int i, int j);
  friend ostream& operator<<(ostream& stream, const Matrix& matrix);
  int find_max_el(int i, int& str);
  ~Matrix();//Деструктор
 void method_gaussa();
 void print_X();
 void interface();
 void solve();
};