#pragma once
#include "Function.h"
#include <cmath>
#include <iostream>

function::function(double _point)
{
	this->point = _point;
}

double function::value(double _x)
{
	double n;
	this->point = _x;
	n = pow(point, 3) + 4.0 * point - 3.0;
	return n;
}

double function::derivative(double _x)
{
	double n;
	this->point = _x;
	n = 3.0 * pow(point, 2) + 4.0;
	return n;
}

void function::OnTheSegment()
{
	double a, b, c, point, n;
	a = 1.0, b = 5.0, c = 2.0;
	std::cout << "3. Значение функции в точке:" << std::endl;
	for (double i = a; i < b; i = i + c)
	{
		point = i;
		n = pow(point, 3) + 4.0 * point - 3.0;
		std::cout << "(" << point << ")" << ": " << n << std::endl;
	}
}
