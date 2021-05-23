#pragma once
#include "Function.h"
class Parabola :
    public Function
{
    double f(double _x)
    {
        x = _x;
        return x * x - 2 * x + 1;
    }

    double pf(double  _x)
    {
        x = _x;
        return 2.0 * x - 2;
    }
};