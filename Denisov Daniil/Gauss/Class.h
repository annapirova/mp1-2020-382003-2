#include<iostream>
#include <iomanip>
using namespace std;
class matrixs
{
private:
  int width, high;
  double** matrix;
public:
  matrixs(const int phigh, const int pwidth);//Создание матрицы
  void zapolnenie();
  void print();
  matrixs& operator=(const matrixs& m);//Не понадобилось
  matrixs& operator*(const int a);//Выделяет ведущую единицу в столбце [a][a]
  matrixs& operator+(/**/const int str);//Обнуляет столбец а
  matrixs& method_gausa();
  void SetEl(matrixs&m,const int line,const int column);
};
