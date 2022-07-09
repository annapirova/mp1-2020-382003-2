#include "Vector.h"
#include "Matrix.h"

void Matrix::method_gaussa()
{
	for (int i = 0; i < sizematr; i++)//Если i<size последним действием переставляет первую и последнюю строку(решение не меняет)
	{
		int counter = 1;//выход за пределы матрицы
		double temp = 1;//Коэф,с которым нужно сложить две строки
		Vector _temp;//Вектор строки,которую складываем(для избежания кучи делений и умножений)
		int temp_str = 0;//Строка,в которой найден максимальный элемент
		if (sizematr > i + 1)
		{
			double max_el_stolb = this->find_max_el(i, temp_str);
			this->change_str(i, temp_str);
			b.change_str(i, temp_str);
		}
		for (int j = i + 1; j < sizematr; j++) // i+1
		{
			//if (i + k < size)
			//{
			if (matr[j][i] != 0)//Если = 0,значит элемент зануляется "автоматически"
			{
				_temp = matr[i];
				temp = matr[j][i] / matr[i][i];

				for (int k = 0; k < sizematr; k++)
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
			cout << "temp\n" << *(this);
			counter++;
		}
		//matr[i] /= temp;
		//b[i] /= temp;
		//temp = matr[i][i];
		//matr[i] /= temp ;
		//b[i] /= temp ;
	}
	//Запись ответа 
	for (int i = sizematr - 1; i >= 0; i--)
	{
		X[i] = b[i];
		for (int j = i + 1; j<sizematr; j++)
			X[i] -= matr[i][j] * X[j];

		X[i] /= matr[i][i];
	}
}