#pragma once
#include <iostream>

class Complex
{
public:
  double Re;
  double Im;
public:
  Complex();
  Complex(double re, double im);
  Complex(const Complex& z);
  ~Complex();
  void Print();
  double GetRe() { return Re; };
  double GetIm() { return Im; };

  Complex operator+(const Complex& z);
  Complex& operator=(const Complex& z);

  friend std::ostream& operator<<(std::ostream& os, const Complex& v);
};