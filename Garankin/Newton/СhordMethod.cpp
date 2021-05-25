#pragma once
#include "ÑhordMethod.h"
#include "Function.h"
#include <iostream>
#include <math.h>
#define eps 0.000001


double ChordMethod::method(functions* fx)
{
    double a = 1, b = 1.2;
	double Fa = fx->value(a);
    double Fb = fx->value(b);

    while (fabs(b - a) > eps) 
    {
        Fa = fx->value(a);
        Fb = fx->value(b);
        a = b - (b - a) * Fb / (Fb - Fa);
        b = a - (a - b) * Fa / (Fa - Fb);
    }

    return b;
}
