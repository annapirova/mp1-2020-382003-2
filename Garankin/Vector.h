#pragma once
class Vector
{
private:
	int size;
	double* Vec;

public:
	void Print();
	void Input();
	Vector();
	Vector(int size);
	Vector(const Vector& v2);
	void GeneratorSystem(int size);
	double& operator [](int i);
	Vector operator +(const Vector& v2) const;
	Vector operator -(const Vector& v2) const;
	Vector& operator =(const Vector& v2);
	~Vector();

	friend class Gauss;
	friend class Matrix;
};

//class Matr1
//{
//private:
//	int size1;
//	int size2;
//
//	double** Mat;
//
//public:
//};
//
//class Matr2
//{
//private:
//	int size1;
//	int size2;
//
//	Vector* Mat;
//
//public:
//	Matr2(int size1_, int size2)
//	{
//		Mat = new Vector[size1];
//		for (int i = 0; i < size1; i++)
//			Mat[i] = Vector(size2);
//	}
//
//	Matr2& operator =(const Matr2& m)
//	{
//		for (int i = 0; i < size1; i++)
//			Mat[i] = m.Mat[i];
//	}
//	
//};