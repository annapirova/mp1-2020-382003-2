#pragma once
#include <iostream>
#include <initializer_list>
#include "complex.h"

//class Vector
//{
//	int size;
//	int capacity;
//	double* values;
//public:
//	Vector(int n);
//	Vector(int n, double* val);
//	Vector(const Vector& v2);
//
//	Vector(std::initializer_list<double> l);
//	
//	Vector(int n, double val);
//
//	~Vector();
//	Vector& operator=(const Vector& v2);
//	void SetRandValues(double min, double max);
//	double& operator[](int i);
//	const double& operator[](int i) const;
//	
//	void reserve(int newSize);
//
//
//	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
//};

class Vector
{
	int size;
	int capacity;
	Complex* values;
public:
	Vector(int n);
	Vector(int n, Complex* val);
	Vector(const Vector& v2);

	Vector(std::initializer_list<Complex> l);

	~Vector();
	//Vector& operator=(const Vector& v2);
	Complex& operator[](int i);
	const Complex& operator[](int i) const;

	void reserve0(int newSize);
	void reserve1(int newSize);
	void reserve2(int newSize);

	void push_back(const Complex& c);

	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

