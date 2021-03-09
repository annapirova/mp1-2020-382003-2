#include "triangle.h"
#include "Complex.h"
#include <iostream>

using namespace std;

void main1()
{
	Triangle t1, t2(2.3, 3.2, 1.5), t3(t2);

	double per1 = t1.GetPer();
	double per2 = t2.GetPer();
	double per3 = t3.GetPer();
	double sqr2 = t2.GetSqr();
	double sqr3 = t3.GetSqr();
	double sqr1 = t1.GetSqr();

	cout << "Perimeter:\n" << per1 << endl << per2 << endl << per3 << endl;
	cout << "__________________________________________________________" << endl;
	cout << "Square:\n" << sqr1 << endl << sqr2 << endl << sqr3 << endl;
	cout << "__________________________________________________________" << endl;
	
	t1.~Triangle();
	t2.~Triangle();
	t3.~Triangle();
}

int main()
{
	Complex t, a(1, 1), b(2, 3), c, d;

	c = a + b;
	c.Print();
	cout << endl << endl;
	c = a - b;
	c.Print();
	cout << endl << endl;
	c = a * b;
	c.Print();
	cout << endl << endl;
	c = a / b;
	c.Print();
	cout << endl << endl;
	t = d = b;
	t.Print();
	cout << endl << endl;
	d.Print();




	return 0;
}