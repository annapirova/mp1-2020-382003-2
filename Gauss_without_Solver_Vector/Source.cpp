#include "Header.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество строк";
	cin >> N;
	Matrix mat(N);			  //Создаёт матрицу А размера n*(n+1), где последний столбец это вектор b
	//mat.insert();			 //Эта функция позволяет заполнить матрицу своими руками 
	mat.random(100);		//Заполняет матрицу случаными числами, в том числе и вектор b
	mat.PRINT();		   //Выводит полноценно матрицу и вектор b
	mat.gaus();			  //Метод Гаусса
	mat.PRINT();
	mat.exit();
	mat.proverka();

	system("pause");
}