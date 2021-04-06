#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

int main()
{
	srand(unsigned int(time(NULL)));
	try
	{
		matrix a(5, 5, 10);
		vector x(5), b(5, 10);
		Solver ex(a, x, b);

		ex.PrintM();
		ex.Gauss();
		ex.PrintAns();
		cout << "Correct answer? - " << ex.Check() << endl;
		cout << endl << "JACOBI:" << endl;
		ex.Jacobi();
	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
	}
	
	cout << endl << "end";
	return 0;
}