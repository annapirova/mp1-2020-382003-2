#pragma once
#include "functions.h"
#include "Function.h"
#include "methods.h"
class solver
{
public:
	void print(functions *functionI, double _x);
	void method(methods* method, functions* fx);
};