#pragma once
#include "NewtonMethod.h"
#include "Function.h"
#include <iostream>
#include <math.h>
#define eps 0.000001


double NewtonMethod::method(functions* fx)
{
	double x0 = 2;
	double Fx = fx->value(x0);
	double dfx = fx->derivative(x0);


	double x1 = x0 - Fx / dfx; 
	while (fabs(x1 - x0) > eps) { 
		x0 = x1;
		Fx = fx->value(x0);
		dfx = fx->derivative(x0);
		x1 = x0 - Fx / dfx; 
	}
	return x1;
}
