#include "triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle()
{
	a = 1.0;
	b = 1.0;
	c = 1.0;
}

Triangle::Triangle(double a0, double b0, double c0)
{
	a = a0;
	b = b0;
	c = c0;
}

Triangle::Triangle(const Triangle &t)
{
	a = t.a;
	b = t.b;
	c = t.c;
}

Triangle::~Triangle()
{
	cout << "deleted" << endl;
}

double Triangle::GetPer()
{
	return a + b + c;
}

double Triangle::GetSqr()
{
	double p = GetPer() / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}
