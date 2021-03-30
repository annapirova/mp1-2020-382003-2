#include <iostream>

class VEC;
class MAT;

//КЛАСС МЕТОД ГАУССА
class MG
{   public:
    int n;
    MAT* A;
    MAT& A_=*A;
    VEC* B;
    VEC& B_=*B;
    VEC* X;
    VEC& X_=*X;
    int flag=0;
    
public:
	//конструкторы для метдоа Гаусса 
	MG(int n_=1);

	//передача значений по ссылке для метода Гаусса
	MAT& Matrix();
	VEC& Vector_B();
	VEC& Vector_X();
	
    //рандомное задание для метода Гаусса
	void RAND();
	
	//Решение для метода Гаусса
	void DEC();
	
	//перегрузка ввода и вывода для вектора 
	friend std::istream& operator>> (std::istream &is, MG &pop);
	friend std::ostream& operator<< (std::ostream &os, const MG &pop);

};
