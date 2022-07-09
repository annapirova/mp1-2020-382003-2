#include "Vector.h"

Vector::Vector(int n)
{
	sizematr = n;
	vect = new double[sizematr];
}

Vector::Vector(const Vector& v2)
{
	sizematr = v2.sizematr;
	vect = new double[sizematr];
	for (int i = 0; i < sizematr; i++) {
		vect[i] = v2.vect[i];
	}
}

Vector::~Vector()
{
	delete[] vect;
	vect = nullptr;
}

void Vector::init()
{
	int rand_max = 500;
	for (int i = 0; i < sizematr; i++)
	{
		vect[i] = rand() % rand_max;
	}
}

Vector& Vector::operator=(const Vector& v2)
{
	if (this == &v2)
		return *this;
	delete[] vect;
	vect = new double[v2.sizematr];
	sizematr = v2.sizematr;
	for (int i = 0; i < sizematr; i++) {
		vect[i] = v2.vect[i];
	}
	return *this;
}

Vector& Vector::operator+=(const Vector& v2)
{
	for (int i = 0; i < sizematr; i++)
	{
		vect[i] += v2.vect[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v2)
{
	for (int i = 0; i < sizematr; i++)
	{
		vect[i] -= v2.vect[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& v2)
{
	Vector new_vector(v2.sizematr);
	for (int i = 0; i < sizematr; i++)
	{
		new_vector.vect[i] = vect[i] + v2.vect[i];
	}
	return new_vector;
}

Vector& Vector::operator*=(double k)
{
	for (int i = 0; i < sizematr; i++)
	{
		vect[i] *= k;
	}
	return *this;
}

Vector& Vector::operator/=(double k)
{
	for (int i = 0; i < sizematr; i++)
	{
		vect[i] /= k;
	}
	return *this;
}

double& Vector::operator[](int ind)
{
	if (ind > sizematr)
		throw std::exception();
	return vect[ind];
}

void Vector::change_str(int i, int j)
{
	double temp = vect[i];
	vect[i] = vect[j];
	vect[j] = temp;
}

ostream& operator<<(ostream& stream, const Vector& vec)
{
	for (int i = 0; i < vec.sizematr; i++) {
		stream << vec.vect[i] << setfill(' ') << setw(6);
	}
	return stream;
}

void Vector::leading_unit(int i)
{
	int temp = vect[i];
	for (int k = 0; k < sizematr; k++)
	{
		vect[k] /= temp;
	}
	//b[i] /= temp;
}