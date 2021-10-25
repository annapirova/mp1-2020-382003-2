#include "Vector.h"
#include <cstdlib>
#include <initializer_list>
#include <memory>

//Vector::Vector(int n) : size(n), capacity(size)
//{
//	if (n >= 0)
//	{
//		values = new double[n];
//	}
//	else
//	{
//		throw std::exception("Wrong vector size");
//	}
//}
//
//Vector::Vector(int n, double* v) : Vector(n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		values[i] = v[i];
//	}
//}
//
//void Vector::SetRandValues(double min, double max)
//{
//	for (int i = 0; i < size; i++)
//	{
//		values[i] = min + (double)rand() / (double)RAND_MAX * (max - min);
//	}
//}
//
//Vector::Vector(const Vector& v) : size(v.size)
//{
//	values = new double[size];
//	for (int i = 0; i < size; i++)
//	{
//		values[i] = v.values[i];
//	}
//}
//
//Vector::Vector(std::initializer_list<double> l) : Vector(l.size())
//{
//	//size = l.size();
//	std::copy(l.begin(), l.end(), values);
//}
//
//void Vector::reserve(int newSize)
//{
//	if (newSize > capacity)
//	{
//		//double* newArr = new double[newSize];
//		// 1. выделится память на newSize объектов
//		// 2. вызовется конструктор по уомлчанию для этих объектов
//
//		double* newArr = (double*)(new char[newSize * sizeof(double)]);
//		                 //(double*)malloc(newSize * sizeof(double));
//		// 1. выделится память на newSize объектов
//
//		for (int i = 0; i < size; i++)
//		{
//			newArr[i] = values[i];
//		}
//		delete[] values;
//		values = newArr;
//
//		capacity = newSize;
//	}
//}
//
//
//
//
////Vector::Vector(std::initializer_list<double> l)
////{
////	size = l.size();
////	values = new double[size];
////	std::copy(l.begin(), l.end(), values);
////	
////	//std::initializer_list<double>::iterator it;
////	//for (int i = 0, it = l.begin(); it != l.end(); it++, i++)
////	//{
////	//	values[i] = *it;
////	//}
////}
//
//
//Vector::Vector(int n, double val) : Vector(n)
//{
//	for (int i = 0; i < n; i++)
//		values[i] = val;
//}
//
//
//Vector::~Vector()
//{
//	delete[] values;
//}
//
//Vector& Vector::operator=(const Vector& v)
//{
//	if (this == &v)
//		return *this;
//	else if (size == v.size)
//	{
//		for (int i = 0; i < size; i++)
//			values[i] = v.values[i];
//		return *this;
//	}
//	else
//	{
//		delete[] values;
//
//		size = v.size;
//		values = new double[size];
//		for (int i = 0; i < size; i++)
//			values[i] = v.values[i];
//		return *this;
//	}
//}
//
//double& Vector::operator[](int i)
//{
//	if (i < 0 || i >= size)
//		throw std::exception("Wrong index");
//	return values[i];
//}
//
//const double& Vector::operator[](int i) const
//{
//	if (i < 0 || i >= size)
//		throw std::exception("Wrong number of values");
//	return values[i];
//}
//
//


Vector::Vector(int n) : size(n), capacity(size)
{
	if (n >= 0)
	{
		values = (Complex*)(new char[size * sizeof(Complex)]);
	}
	else
	{
		throw std::exception("Wrong vector size");
	}
}

Vector::~Vector()
{
	std::cout << "vector destructor\n";
	delete[] (char*)values;
}

Vector::Vector(int n, Complex* v) : Vector(n)
{
	for (int i = 0; i < n; i++)
	{
		values[i] = v[i];
	}
}


Vector::Vector(const Vector & v) : Vector(v.size)
{
	for (int i = 0; i < size; i++)
	{
		values[i] = v.values[i];
	}
}

Vector::Vector(std::initializer_list<Complex> l) : Vector(l.size())
{
	std::copy(l.begin(), l.end(), values);
}

void Vector::reserve0(int newSize)
{
	if (newSize > capacity)
	{
		// 1. выделится память на newSize объектов
		// 2. вызовется конструктор по уомлчанию для этих объектов
		Complex* newArr = new Complex[newSize];
		for (int i = 0; i < size; i++)
			newArr[i] = values[i];
		delete[] values;
		values = newArr;
	}
}

void Vector::reserve1(int newSize)
{
	if (newSize > capacity)
	{
		// 1. выделится память на newSize объектов
		Complex* newArr = (Complex*)(new char[newSize * sizeof(Complex)]);
		// вызов конструкторов копирования по нужному адресу
		// 2. placement new -- вызовем конструктор для size объектов
		for (int i = 0; i < size; i++)
		{
			new(newArr + i) Complex(values[i]);
		}

		// мы хотим удалить из values size объектов, а не столько, сколько было выделено
		for (int i = 0; i < size; i++)
		{
			(values + i)->~Complex();
		}
		delete[] (char*)values;
		
		values = newArr;

		capacity = newSize;
	}
}

void Vector::reserve2(int newSize)
{
	if (newSize > capacity)
	{
		// 1. выделится память на newSize объектов
		Complex* newArr = (Complex*)(new char[newSize * sizeof(Complex)]);
		// вызов конструкторов копирования по нужному адресу
		// аналог placement new
		// https://en.cppreference.com/w/cpp/memory/uninitialized_copy
		std::uninitialized_copy(values, values + size, newArr);

		// мы хотим удалить из values size объектов, а не столько, сколько было выделено
		for (int i = 0; i < size; i++)
		{
			(values + i)->~Complex();
		}
		delete[](char*)values;

		values = newArr;

		capacity = newSize;
	}
}

void Vector::push_back(const Complex& c)
{
	if (size == capacity)
	{
		reserve1(2 * size);
	}
	// вызов конструктора по адресу "values + size"
	new(values + size) Complex(c);
	size++;
}




//Vector::Vector(std::initializer_list<double> l)
//{
//	size = l.size();
//	values = new double[size];
//	std::copy(l.begin(), l.end(), values);
//	
//	//std::initializer_list<double>::iterator it;
//	//for (int i = 0, it = l.begin(); it != l.end(); it++, i++)
//	//{
//	//	values[i] = *it;
//	//}
//}


//Vector::Vector(int n, Complex* val) : Vector(n)
//{
//	for (int i = 0; i < n; i++)
//		values[i] = val;
//}




//Vector& Vector::operator=(const Vector & v)
//{
//	if (this == &v)
//		return *this;
//	else if (size == v.size)
//	{
//		for (int i = 0; i < size; i++)
//			values[i] = v.values[i];
//		return *this;
//	}
//	else
//	{
//		delete[] values;
//
//		size = v.size;
//		values = new double[size];
//		for (int i = 0; i < size; i++)
//			values[i] = v.values[i];
//		return *this;
//	}
//}

Complex& Vector::operator[](int i)
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong index");
	return values[i];
}

const Complex& Vector::operator[](int i) const
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong number of values");
	return values[i];
}


std::ostream& operator<<(std::ostream & os, const Vector & v)
{
	os << "size: " << v.size << " cap: " << v.capacity << " vals: ";
	for (int i = 0; i < v.size; i++)
		os << v.values[i] << " ";
	os << std::endl;
	return os;
}