#pragma once
#include"Function.h"
class methods
{
public:
	double eps, x, answer;
	virtual double method(functions* fx) = 0;
};