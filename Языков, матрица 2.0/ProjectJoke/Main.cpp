#include"Matrix.h"
#include "Vector.h"
int main()
{
	srand(time(NULL));
	int sizematr;
	cout << "What is the size of the system?";
	cin >> sizematr;
	//srand(time(NULL));
	Matrix m1(sizematr, 100);
	m1.interface();
	m1.method_gaussa();
	m1.print_X();
	m1.solve();
	_getwche();
	return 0;
}