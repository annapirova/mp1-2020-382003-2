#include "Vector.h"
#include "Matrix.h"

void Matrix::method_gaussa()
{
	for (int i = 0; i < sizematr; i++)//���� i<size ��������� ��������� ������������ ������ � ��������� ������(������� �� ������)
	{
		int counter = 1;//����� �� ������� �������
		double temp = 1;//����,� ������� ����� ������� ��� ������
		Vector _temp;//������ ������,������� ����������(��� ��������� ���� ������� � ���������)
		int temp_str = 0;//������,� ������� ������ ������������ �������
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
			if (matr[j][i] != 0)//���� = 0,������ ������� ���������� "�������������"
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
	//������ ������ 
	for (int i = sizematr - 1; i >= 0; i--)
	{
		X[i] = b[i];
		for (int j = i + 1; j<sizematr; j++)
			X[i] -= matr[i][j] * X[j];

		X[i] /= matr[i][i];
	}
}