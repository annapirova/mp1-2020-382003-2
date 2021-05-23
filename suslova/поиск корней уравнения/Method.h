#pragma once
#include "Function.h"
class Method
{
public:
	virtual double GetNext(double x_prev, Function* func) = 0;
};