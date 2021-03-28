#include <locale>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


class Matrix {
	int n;
	int i, j, m, k;
	double aa, bb;
	double**A;
	double**B;
	double*x;
	double*b;

public:

	Matrix();
	Matrix(int N);
	void insert();
	void gaus();
	void exit();
	void proverka();
	void random(int m);
	void PRINT();
};

