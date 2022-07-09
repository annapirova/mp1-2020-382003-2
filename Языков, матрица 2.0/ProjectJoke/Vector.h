#ifndef _VECTOR_H
#define _VECTOR_H
#include<iostream>
#include<iomanip>
using namespace std;

class Vector
{
public:
	double* vect;
	int sizematr;
	Vector(int n = 1);
	Vector(const Vector& m2);
	~Vector();
	void init();
	Vector& operator=(const Vector& v2);
	Vector& operator+=(const Vector& v2);
	Vector& operator-=(const Vector& v2);
	Vector operator+(const Vector& v2);
	Vector& operator*=(double k);
	Vector& operator/=(double k);
	double& operator[](int ind);
	void change_str(int i, int j);
	friend ostream& operator<<(ostream& stream, const Vector& vec);
	void leading_unit(int i);
};
#endif