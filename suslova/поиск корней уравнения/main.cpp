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
		cout << "�������� �������:" << endl << "1.��������" << endl << "2.�����" << endl;
		cout << "3.����� ������ ���������" << endl;
		cin >> p;
		switch (p) 
		{
		case 1:
			cout << "�������� �����:" << endl << "1.����� �������" << endl;
			cin >> met;
			switch (met) 
			{
			case 1:
				cout << "������� ����� ������ ��������� �������� � � �����������" << endl;
				double x0, eps;
				cin >> x0 >> eps;
				f = new Parabola();
				m = new Newton();
				cout << "��������������� �����: " << s.solvation(x0, eps, f, m) << endl;
			}
		case 2:
			cout << "�������� �����:" << endl << "1.����� �������" << endl;
			cin >> met;
			switch (met) 
			{
			case 1:
				cout << "������� ����� ������ ��������� �������� � � �����������" << endl;
				double x0, eps;
				cin >> x0 >> eps;
				f = new Sin();
				m = new Newton();
				cout << "��������������� �����: " << s.solvation(x0, eps, f, m) << endl;
			}
		case 3:
			break;
		}
	}
}