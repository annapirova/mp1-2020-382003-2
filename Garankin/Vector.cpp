#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <ctime>

using namespace std;


void Vector::Print()
{
	cout << "Ваш вектор: ";
	for (int i = 0; i < size; i++)
	{
		cout << Vec[i] << "  ";
	}
	cout << "\n"; 
}


void Vector::Input()
{
	cout << "Введите элементы вектора: ";
	for (int i = 0; i < size; i++)
	{
		cin >> Vec[i];
	}
}


Vector::Vector()
{
	this->size = 10;
	this->Vec = new double[size];
	for (int i = 0; i < size; i++)
	{
		Vec[i] = 0;
	}
}


Vector::Vector(int size)
{
	this->size = size;
	this->Vec = new double  [size];
}


Vector::Vector(const Vector& other)
{
	this->size = other.size;
	this->Vec = new double[size];
	for (int i = 0; i < size; i++)
	{
		this->Vec[i] = other.Vec[i];
	}
}


double& Vector:: operator [](int i)
{
	return Vec[i];
}


Vector Vector:: operator +(const Vector& other) const
{	
	Vector T(other.size);
	for (int i = 0; i < size; i++)
	{
		T.Vec[i] = this->Vec[i] + other.Vec[i];
	}
	return T;
}


Vector Vector:: operator -(const Vector& other) const
{
	Vector T(other.size);
	for (int i = 0; i < size; i++)
	{
		T.Vec[i] = this->Vec[i] - other.Vec[i];
	}
	return T;
}


void Vector::GeneratorSystem(int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		this->Vec[i] = rand() % 100;
	}
}


Vector& Vector:: operator =(const Vector& other)
{
	if (this == &other)
	{
		return * this;
	}

	if (this-> size != other.size) 
	{
		delete[] Vec;
		this->Vec = new double[other.size];
		this->size = other.size;
	}
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
