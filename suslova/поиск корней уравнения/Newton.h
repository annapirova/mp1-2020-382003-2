#pragma once
#include "Method.h"
class Newton :
    public Method
{
    double GetNext(double x_prev, Function* func)
    {
        return x_prev - func->f(x_prev) / func->pf(x_prev);
    }
};