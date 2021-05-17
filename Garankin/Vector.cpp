#include "Vector.h"
#include <iostream>
using namespace std;


Vector::Vector()
{
	this->size = 10;
	for (int i = 0; i < size; i++)
	{
		Vec[i] = 0;;
	}
	cout << "Ваш вектор: ";
	for (int i = 0; i < size; i++)
	{
		cout << Vec[i] << "  ";
	}
	cout << "\n";
}


Vector::Vector(int size)
{
	this->size = size;
	this->Vec = new double  [size];
	cout << "Введите элементы вектора: ";
	for (int i = 0; i < size; i++)
	{
		cin >> Vec[i];
	}
	cout << "Ваш вектор: ";
	for (int i = 0; i < size; i++)
	{
		cout << Vec[i] << "  ";
	}
	cout << "\n";
}


Vector::Vector(const Vector& other)
{
	this->size = other.size;
	this->Vec = new double[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->Vec[i] = other.Vec[i];
	}
}


Vector Vector:: operator +(const Vector& other)
{	
	Vector T;
	this->size = other.size;
	this->Vec = new double[other.size];
	for (int i = 0; i < other.size; i++)
	{
		T.Vec[i] = this->Vec[i] + other.Vec[i];
	}
	return T;
}


Vector& Vector:: operator =(const Vector& other)
{
	this->size = other.size;
	this->Vec = new double[other.size];
	delete this->Vec;
	for (int i = 0; i < other.size; i++)
	{
		this->Vec[i] = other.Vec[i];
	}
	return *this;
}


Vector :: ~Vector()
{
	delete[]Vec;
}
