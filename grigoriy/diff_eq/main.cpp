/*
#include <iostream>
using namespace std;

int main(){
    double x, y, h, a, b;
    int n = 8;
    a = 0.0;
    b = 1.0;
    h = (b - a) / n;
    x = a;
    y = 0.5;




    return 0;
}*/
#include <stdio.h>

double func(double x, double y)
{
    return 6*x*x+5*x*y; // функция первой производной
}

int main(int argc, char** argv)
{
    int i, n;
    double x, y, h;

    h = 0.01; // шаг
    n = 10; // количество итераций
    x = 1; // x0
    y = 1; // y0

    for (i = 0; i < n; i++)
    {
        y += h * func(x, y); // вычисление yi
        x += h;
    }
    printf("%lf", y);

    return 0;
}