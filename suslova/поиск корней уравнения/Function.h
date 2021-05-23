#pragma once
class Function
{
protected:
	double x;
public:
	virtual double f(double _x) = 0;
	virtual double pf(double _x) = 0;
};