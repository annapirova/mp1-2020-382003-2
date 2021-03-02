#include <iostream>
#include "complex.h"

using namespace std;

Complex::Complex()
{
	a = 0.0;
	b = 0.0;
}
Complex::Complex(double a0, double b0)
{
	a = a0;
	b = b0;
}
Complex::Complex(const Complex& z)
{
	a = z.a;
	b = z.b;
}

void Complex::Add(Complex z1, Complex z2)
{
	a = z1.a + z2.a;
	b = z1.b + z2.b;
}

void Complex::Sub(Complex z1, Complex z2)
{
	a = z1.a - z2.a;
	b = z1.b - z2.b;
}

void Complex::Mult(Complex z1, Complex z2)
{
	a = z1.a * z2.a - z1.b * z2.b;
	b = z1.a * z2.b + z1.b * z2.a;
}

void Complex::Div(Complex z1, Complex z2)
{
	a = (z1.a * z2.a + z1.b * z2.b) / (z2.a * z2.a + z2.b * z2.b);
	b = (z1.b * z2.a - z1.a * z2.b) / (z2.a * z2.a + z2.b * z2.b);
}
void Complex::Print()
{
	if (b > 0)
	{
		cout.precision(2);
		cout << a << "+" << b << "i";
	}
	else if (b < 0)
	{
		cout.precision(2);
		cout << a << b << "i";
	}
	else
		cout << a;
}
