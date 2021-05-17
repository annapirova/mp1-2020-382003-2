#include "Gauss.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	int size;
	setlocale(LC_CTYPE, "Russian");
	cin >> size;
	Vector VecX(size);
	Vector VecB(size);
	Gauss MatA(size);	
	Vector CB(size);
	Matrix CA(size,size);
	MatA.GeneratorSystem();
	VecB.GeneratorSystem(size);
	CB = VecB;
	CA = MatA;
	MatA.Print();
	MatA.gauss();
	MatA.Print();
	VecX.Print();
	MatA.Check();
	return 0;
}