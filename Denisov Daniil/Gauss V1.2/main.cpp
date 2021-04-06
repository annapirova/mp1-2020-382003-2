#include"Matrix.h"
#include "Vector.h"
//1)Обратный ход 2)Слежка за сменой X 3)Поиск погрешности
int main()
{
  srand(time(NULL));
  int size;
  cout << "What is the size of the system?";
  cin >> size;
  //srand(time(NULL));
  Matrix m1(size,100);
  m1.interface();
  m1.method_gaussa();
  m1.print_X();
  m1.solve();
  _getwche();
  return 0;
}