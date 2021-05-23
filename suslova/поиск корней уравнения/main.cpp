#include <iostream>
using namespace std;
#include <locale.h>
#include "Function.h"
#include "Method.h"
#include "Parabola.h"
#include "Sin.h";
#include "Newton.h";
#include "Solver.h";

void main() {
	setlocale(LC_CTYPE, "Russian");
	Function* f;
	Method* m;
	Solver s;
	int met;
	int p = 1;
	while (p != 3) 
	{
		cout << "Выберите функцию:" << endl << "1.Парабола" << endl << "2.Синус" << endl;
		cout << "3.Конец работы программы" << endl;
		cin >> p;
		switch (p) 
		{
		case 1:
			cout << "Выберите метод:" << endl << "1.Метод Ньютона" << endl;
			cin >> met;
			switch (met) 
			{
			case 1:
				cout << "Введите через пробел начальное значение х и погрешность" << endl;
				double x0, eps;
				cin >> x0 >> eps;
				f = new Parabola();
				m = new Newton();
				cout << "Приблизительный ответ: " << s.solvation(x0, eps, f, m) << endl;
			}
		case 2:
			cout << "Выберите метод:" << endl << "1.Метод Ньютона" << endl;
			cin >> met;
			switch (met) 
			{
			case 1:
				cout << "Введите через пробел начальное значение х и погрешность" << endl;
				double x0, eps;
				cin >> x0 >> eps;
				f = new Sin();
				m = new Newton();
				cout << "Приблизительный ответ: " << s.solvation(x0, eps, f, m) << endl;
			}
		case 3:
			break;
		}
	}
}