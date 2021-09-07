#include "line.h"

void main1()
{
	point p1(5.5, -3.4);
	p1.Print();

	//Line l1;
	Line l2(3);
	double c[5] = { 10, 20, 30, 40, 50 };
	double c2[5] = { 100, 200, 300};
	Line l3(c, 5);
	//l1.Print();
	l2.Print();
	l3.Print();
	Line l4(l3);
	l4.Print();

	l2 = l3;
	l2.Print();
	l4 = Line(c2, 3);
	l4.Print();

	Line l5 = l4 + l3;
	std::cout << "l4 + l3 = " << l5 << "\n";
	std::cout << "l5[2] = " << l5[2] << "\n";
	std::cout << "l5[10] = " << l5[10] << "\n";
}


void main()
{
	double c[6] = { 1.0, 1.0, 3.0, 1.0, 1.0, 3.0 };
	ClosedLine t(c, 6);
	t.Print(); // метод класса Line
}
