#pragma once
#include "solver.h"

void solver::print(functions* functionI, double _x)
{
	functionI->value(_x);
	functionI->derivative(_x);
	functionI->OnTheSegment();
}

void solver::method(methods* method, functions* fx)
{
	method->method(fx);
}