#include "triangle.h"
#include <iostream>

using namespace std;

void main()
{
	Triangle t1, t2(2.3, 3.2, 1.5), t3(t2);
	double per1 = t1.GetPer();
	double per2 = t2.GetPer();
	double per3 = t3.GetPer();

	cout << "Perimeter:\n" << per1 << endl << per2 << endl << per3 << endl;
	
	t1.~Triangle();
}