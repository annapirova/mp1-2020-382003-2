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


void main2()
{
	double c[6] = { 1.0, 1.0, 3.0, 1.0, 1.0, 3.0 };
	ClosedLine t(c, 6);
	t.Print(); // метод класса Line
}

void main()
{
	int nF = 4;
	ClosedLine** figures = new ClosedLine* [nF];
	srand(1000);
	for (int i = 0; i < nF; i++)
	{
		
		double x1, y1, x2, y2, d;
		x1 = (double)rand() / (double)RAND_MAX * 10.0;
		y1 = (double)rand() / (double)RAND_MAX * 10.0;
		x2 = (double)rand() / (double)RAND_MAX * 5.0;
		y2 = (double)rand() / (double)RAND_MAX * 5.0;
		point p1(x1, y1);
		point p2(x2, y2);
		
		int r = rand() % 2;
		if (r == 0)
			figures[i] = new Rect(p1, p2);
		else
			figures[i] = new Triangle(p1, p2);
	}

	for (int i = 0; i < nF; i++)
	{
		figures[i]->Print();
	}

	for (int i = 0; i < nF; i++)
	{
		figures[i]->Resize(1, 2.5);
	}

	for (int i = 0; i < nF; i++)
	{
		figures[i]->Print();
	}

	delete [] figures;
}
