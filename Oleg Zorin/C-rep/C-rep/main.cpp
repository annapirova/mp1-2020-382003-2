#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

int main()
{
	matrix a(5, 5, 100);
	vector x(5), b(5, 100);
	Solver ex(a, x, b);
	
	ex.PrintM();
	ex.Gauss();
	ex.PrintAns();
	cout << ex.Check() << endl;

	cout << "end" << endl;
	return 0;
}