#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

int main()
{
	try
	{
		matrix a(25, 25, 100);
		vector x(25), b(25, 100);
		Solver ex(a, x, b);

		ex.PrintM();
		ex.Gauss();
		ex.PrintAns();
		cout << ex.Check() << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	

	return 0;
}