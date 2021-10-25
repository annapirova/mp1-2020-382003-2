#include "complex.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Complex::Complex(double re, double im)
{
  Re = re;
  Im = im;
}

Complex::Complex()
{
  Re = 0.0;
  Im = 0.0;
}

Complex::Complex(const Complex& z)
{
  Re = z.Re;
  Im = z.Im;
}

Complex Complex::operator+(const Complex& z)
{
  return Complex(Re + z.Re, Im + z.Im);
}

Complex& Complex::operator=(const Complex& z)
{
  Re = z.Re;
  Im = z.Im;
  return (*this);
}


void Complex::Print()
{
  cout << Re << " + " << Im << "*i" << endl;
}

Complex::~Complex()
{
	cout << "complex destructor\n";
}

std::ostream& operator<<(std::ostream& os, const Complex& v)
{
	os << v.Re << "+" << v.Im << "*i";
	return os;
}
