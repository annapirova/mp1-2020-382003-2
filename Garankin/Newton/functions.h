#pragma once
class functions
{
public:
	double point;
	virtual double value(double _x) = 0;
	virtual double derivative(double _x) = 0;
	virtual void OnTheSegment() = 0;
};