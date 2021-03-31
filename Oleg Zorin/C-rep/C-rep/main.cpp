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
		matrix a(25, 25, 100);
		vector x(25), b(25, 100);
		Solver ex(a, x, b);

		ex.PrintM();
		ex.Gauss();
		ex.PrintAns();
		cout << "Correct answer? - " << ex.Check() << endl;
	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
	}
	
	cout << endl << "end";
	return 0;
}