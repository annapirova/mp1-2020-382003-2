#include "Vector.h"
#include <vector>

using namespace std;

//void main1()
//{
//	//Vector v(5);
//	//v.SetRandValues(-5, 5);
//	//std::cout << v;
//
//	double arr[5] = { 0.5, 1.5, 2.5, 3.5, 4.5 };
//	Vector v2(5, arr);
//	std::cout << v2;
//
//	//Vector v3{ 0.5, 1.5, 2.5, 3.5, 4.5 };
//	//std::cout << v3;
//
//	//Vector v5({ 2, 3.5 });
//	//std::cout << v5;
//
//
//	Vector v6{2, 3.5};
//	std::cout << v6;
//
//	//Vector v3{ 2, 3, 4 };
//	//std::cout << v3;
//
//	//Vector v1 = { 4.5, 5.5, 6.5 }; // вызов конструктора
//	//std::cout << v1;
//
//	//Vector v4(2, 3.5);
//	//std::cout << v4;
//}


void main()
{
	Vector v3{ Complex(1, 2), Complex(3, 4) };
	cout << "reserve start\n";
	v3.reserve1(10);
	cout << v3 << endl;
	v3.push_back(Complex(5, 6));
	cout << v3 << endl;
	v3.reserve2(15);
	cout << v3 << endl;
}