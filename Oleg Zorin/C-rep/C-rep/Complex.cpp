#include <iostream>
#include "complex.h"

using namespace std;

Complex::Complex()
{
	this->Re = 0.0;
	this->Im = 0.0;
}
Complex::Complex(double Re, double Im)
{
	this->Re = Re;
	this->Im = Im;
}
Complex::Complex(const Complex& other)
{
	this->Re = other.Re;
	this->Im = other.Im;
}

Complex& Complex::operator=(const Complex& other)
{
	this->Re = other.Re;
	this->Im = other.Im;

	return *this;
}

Complex Complex::operator+(const Complex& other)
{
	Complex res;

	res.Re = this->Re + other.Re;
	res.Im = this->Im + other.Im;

	return res;
}

Complex Complex::operator-(const Complex& other)
{
	Complex res;

	res.Re = this->Re - other.Re;
	res.Im = this->Im - other.Im;

	return res;
}

Complex Complex::operator*(const Complex& other)
{
	Complex res;
	
	res.Re = this->Re * other.Re - this->Im * other.Im;
	res.Im = this->Re * other.Im + this->Im * other.Re;

	return res;
}

Complex Complex::operator/(const Complex& other)
{
	Complex res;

	res.Re = (this->Re * other.Re + this->Im * other.Im) / (other.Re * other.Re + other.Im * other.Im);
	res.Im = (this->Im * other.Re - this->Re * other.Im) / (other.Re * other.Re + other.Im * other.Im);

	return res;
}

void Complex::Print()
{
	if (Im > 0)
	{
		cout.precision(2);
		cout << Re << "+" << Im << "i";
	}
	else if (Im < 0)
	{
		cout.precision(2);
		cout << Re << Im << "i";
	}
	else
	{
		cout.precision(2);
		cout << Re;
	}
}
