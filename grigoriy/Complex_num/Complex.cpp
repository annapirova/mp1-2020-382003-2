#include "Complex.h"
#include <cmath>

Complex::Complex()
{
    re = 0.0;
    im = 0.0;
}
Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}
Complex::Complex(const Complex &complex_num)
{
    re = complex_num.re;
    im = complex_num.im;
}
Complex::~Complex()
{
    std::cout << std::endl;
}
double Complex::absValue(const Complex &complex_num)
{
    return sqrt(pow(complex_num.re, 2) + pow(complex_num.im, 2));
}
double Complex::absValue1() const
{
    return sqrt(this -> re * this -> re + this -> im * this -> im);
}
Complex Complex::summation(const Complex &complex_num1, const Complex &complex_num2)
{
    return Complex(complex_num1.re + complex_num2.re, complex_num1.im + complex_num2.im);
}
Complex Complex::subtraction(const Complex &complex_num1, const Complex &complex_num2)
{
    return Complex (complex_num1.re - complex_num2.re, complex_num1.im - complex_num2.im);
}
void Complex::getValue(double &r, double &i) const
{
    r = re;
    i = im;
}
void Complex::printValue() const
{
    std::cout << "re = " << this -> re << " im = " << this -> im << std::endl;
}
Complex Complex::operator+(Complex &complex_num) const
{
    return Complex(re + complex_num.re, im + complex_num.im);
}
Complex Complex::operator-(Complex &complex_num) const
{
    return Complex(re - complex_num.re, im - complex_num.im);
}
Complex Complex::operator*(Complex &complex_num) const
{
    return Complex(re * complex_num.re - im * complex_num.im, re * complex_num.im + im * complex_num.re);
}
