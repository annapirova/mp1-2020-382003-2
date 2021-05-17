#pragma once
#include "Matrix.h"
#include "Vector.h"


class Gauss
{
public:
	int size;
		bool needClean;
		Matrix MatA;
		Vector VecB;
		Vector VecX;
		Vector CB;
		Matrix CA;
		Gauss(int Size) : size(Size), MatA(size, size), VecB(size), VecX(size) {};
		void Print();
		Vector gauss();
		void HandInput();
		void GeneratorSystem();
		bool Check();

};