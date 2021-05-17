#include "Vector.h"
#include <iostream>
using namespace std;


int main()
{
	int size;
	cout<<" ¬ведите размер вектора";
	cin >> size;
	setlocale(LC_CTYPE, "Russian");
	Vector vec(size);
	Vector A(size);
	Vector B(size);
	A = vec + B;
	return 0;
}