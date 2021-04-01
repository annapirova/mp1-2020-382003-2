#pragma once
class Vector
{
private:
	int size;
public:
	double* Vec;
	Vector();
	Vector(int size);
	Vector(const Vector& v2);
	Vector operator +(const Vector& v2);
	Vector& operator =(const Vector& v2);
	~Vector();
};


//void Print()
//{
//
//}