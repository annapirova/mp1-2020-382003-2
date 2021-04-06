#include "Vector.h"
#include "Matrix.h"

void Matrix::method_gaussa()
{
  for (int i = 0; i < size; i++)//Если i<size последним действием переставляет первую и последнюю строку(решение не меняет)
  {
    int counter = 1;//Чтобы сложение не выходило за пределы матрицы
    double temp = 1;//Коэф,с которым нужно сложить две строки
    myVector _temp;//Вектор строки,которую складываем(для избежания кучи делений и умножений)
    int temp_str=0;//Строка,в которой найден максимальный элемент
    if (size > i + 1)
    {
      double max_el_stolb = this->find_max_el(i, temp_str);
      this->change_str(i, temp_str);
      b.change_str(i, temp_str);
    }
    for (int j = i+1; j < size; j++) // i+1
    {
      //if (i + k < size)
      //{
        if (matr[j][i] != 0)//Если = 0,значит элемент не нужно занулять...логично
        {
         try
          {
            if (matr[i][i] == 0)
              throw "skip(a/0)";
            else
            {
              _temp = matr[i];
              temp = matr[j][i] / matr[i][i];
            }
          }
          catch (char str[20])
          { 
            temp = 0;
          }


          for (int k = 0; k < size; k++)
          {
            _temp[k] *= temp;
          }
          if (abs(matr[j][i] - _temp[i]) < (1e-9))
          {
            matr[j] -= _temp;
            b[j] -= b[i] * temp;
          }
          else
          {
            matr[j] += _temp;
            b[j] += b[i] * temp;
          }
        }
        //matr[i] /= temp;
      //}
        cout <<"temp\n"<< *(this);
      counter++;
    }
    //matr[i] /= temp;
    //b[i] /= temp;
    //temp = matr[i][i];
    //matr[i] /= temp ;
    //b[i] /= temp ;
  }

  //Записываем ответ 
  for (int i = size-1; i >= 0; i--)
  {
    X[i] = b[i];
    for(int j=i+1;j<size;j++)
      X[i] -= matr[i][j]*X[j];

    try
    {
      if (matr[i][i] != 0)
        X[i] /= matr[i][i];
      else
        throw "bananchik";
    }
    catch (...)
    {
      X[i] = 0;
    }
  }
}

