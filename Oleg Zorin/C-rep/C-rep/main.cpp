#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
	matrix a(100, 100);
	matrix b(1, 2);


	cout << "Standart:\n" << a << endl;
	a.Gauss();
	cout.precision(2);
	cout << "After Gauss:\n" << a << endl;

	cout << "end" << endl;
	return 0;
}