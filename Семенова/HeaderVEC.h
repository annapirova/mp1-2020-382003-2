#include <iostream>

class VEC
{   
    int n;
    double* vec;
    
public:
	//конструкторы 
	VEC(int n_=1);
	VEC(const VEC & V);
	
	//дeструктор для вектора 
	~VEC();
	
	//передача значений по ссылке для вектора
	int V_n() const;
	double* V_arr() const;
	
	//Рандомное заполнение вектора;
	void RAND(int a=1, int b=100);
	
	//перегрузка равно
	VEC& operator = ( const VEC& V);
	
	//перегрузка бинарных операций
	VEC operator + (const VEC& V) const ;  //перегрузка плюса
	VEC operator * (double n) const ; //перегрузка умножения на константу
	
	//перегрузка ввода и вывода
	friend std::istream& operator>> (std::istream &is, VEC &V);
	friend std::ostream& operator<< (std::ostream &os, const VEC &V);
	friend class MAT;
	friend class MG;
};


    
    


