#pragma once
#include "Function.h"
#include "Method.h"
#include "cmath"
#include <iostream>
using namespace std;
#include <locale.h>

class Solver
{
private:
	Function* func;
	Method* meth;
public:
	double solvation(double x_0, double eps, Function* _func, Method* _meth)
	{
		setlocale(LC_CTYPE, "Russian");
		int i = 0;
		double xi, xprev;
		xprev = x_0;
		xi = _meth->GetNext(xprev, _func);
		while (abs(xi - xprev) > eps) 
		{
			xprev = xi;
			xi = _meth->GetNext(xprev, _func);
			i++;
			if ((abs(xi - xprev) > eps)) 
			{
				cout << "Вывести текущую точку(1.Да 0.Нет)?" << endl;
				bool f;
				cin >> f;
				if (f == 1) 
				{
					cout << "x i =" << xi << endl;
				}
			}
		}
		cout << "На поиск корня потребовалось " << i << " итераций" << endl;
		return xi;
	}
};