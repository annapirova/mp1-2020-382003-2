#pragma once
#include "Function.h"
#include <cmath>

class Sin :
    public Function
{
    double f(double _x)
    {
        x = _x;
        return sin(x);
    }

    double pf(double _x)
    {
        x = _x;
        return cos(x);
    }
};
