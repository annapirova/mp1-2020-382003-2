#ifndef COMPLEX_NUM_COMPLEX_H
#define COMPLEX_NUM_COMPLEX_H
#include <iostream>

class Complex {
    double re, im;

public:
    Complex(); // default complex_num
    Complex(double r, double i); // complex_num with set Re and Im
    Complex(const Complex &complex_num); // copy complex_num
    ~Complex();
    double absValue(const Complex &complex_num);
    double absValue1() const;
    Complex summation(const Complex &complex_num1, const Complex &complex_num2);
    Complex subtraction(const Complex &complex_num1, const Complex &complex_num2);
    void getValue(double &r, double &i) const;
    void printValue() const;
    Complex operator+(Complex &complex_num) const;
    Complex operator-(Complex &complex_num) const;
    Complex operator*(Complex &complex_num) const;
};


#endif //COMPLEX_NUM_COMPLEX_H
