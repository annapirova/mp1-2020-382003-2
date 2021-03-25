#include "Class.h";
int main()
{
  int temp;
  int width, high;
  setlocale(LC_ALL, "rus");
  cout << "Введите количество строк:";
  cin >> high;
  cout << "Введите количество коэффициентов:";
  cin >> width;
  matrixs m(high, width);
  do
  {
    cout << "Ввести значения(1) или заполнить автоматически(2)? ";
    cin >> temp;
  } while (temp != 1 && temp != 2);
  if (temp == 1)
  {
    for (int i = 0; i < high; i++)
    {
      for (int j = 0; j < width; j++)
      {
        m.SetEl(m,i,j);
      }
    }
  }
  if (temp == 2)
  {
    m.zapolnenie();
  }

  cout << "Ваша матрица" << endl;
  m.print();

  cout << endl << "Метод гаусса" << endl;
  m.method_gausa();

  cout << "Ответ" << endl;
  m.print();
  return 0;
}