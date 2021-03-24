#include <iostream>
#ifndef HEADERVEC_H
#define HEADERVEC_H

//КЛАСС ВЕКТОР
class VEC
{   public:
    int n;
    double* vec;
    
public:
	//конструкторы для вектора 
	VEC(int n_=1);
	VEC(const VEC & V);

	//дeструктор для вектора 
	~VEC();
	
	//перегрузка равно для вектора 
	VEC& operator = ( const VEC& V);
	
	//перегрузка бинарных операций для вектора 
	VEC operator + (const VEC& V) const ;  //перегрузка плюса для вектора 
	VEC operator * (double n) const ; //перегрузка умножения на число для вектора 
	
	//перегрузка ввода и вывода для вектора 
	friend std::istream& operator>> (std::istream &is, VEC &V);
	friend std::ostream& operator<< (std::ostream &os, const VEC &V);
	
	//Рандомное заполнение вектора;
	void RAND(int a=1, int b=100);
	
//	friend class MAT;
//	friend class MG;
};


//КЛАСС МАТРИЦА
class MAT
{   
    public:
    int n;
    VEC* num;
    
public:
	//конструкторы для матрицы
	MAT(int n_=1);
	MAT(const MAT & M);
	
	//дeструктор для матрицы 
	~MAT();
	
	//перегрузка равно для матрицы
	MAT& operator = ( const MAT& M);
	
	//перегрузка бинарных операций для матрицы
	VEC operator * (const VEC& V) const ;  //перегрузка умножения для матрицы
	
	//перегрузка ввода и вывода для матрицы
	friend std::istream& operator>> (std::istream &is, MAT &M);
	friend std::ostream& operator<< (std::ostream &os, const MAT &M);
	
	//Рандомное заполнение матрицы;
	void RAND(int a=1, int b=100);
//	friend class MG;
};


//КЛАСС МЕТОД ГАУССА
class MG
{   //public:
    int n;
    MAT A;
    VEC B;
    VEC X;
    int flag=0;
    
public:
	//конструкторы для вектора 
	MG(int n_=1);
//	VEC(const VEC & V);
	
	MAT& Matrix();
	VEC& Vector_B();
	VEC& Vector_X();
	void RAND();
	
	void DEC();
	void DEC1();
	void DEC2();
	void DEC3();
	
/*	//перегрузка равно для вектора 
	VEC& operator = ( const VEC& V);
	
	//перегрузка бинарных операций для вектора 
	VEC operator + (const VEC& V) const ;  //перегрузка плюса для вектора 
	VEC operator * (double n) const ; //перегрузка умножения на число для вектора 
*/	
	//перегрузка ввода и вывода для вектора 
	friend std::istream& operator>> (std::istream &is, MG &pop);
	friend std::ostream& operator<< (std::ostream &os, const MG &pop);
	
	//void RAND();
};
#endif
