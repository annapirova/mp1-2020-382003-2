/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "MersenneTwisterGENERATOR.h"

void term();

int main(int argc, char* argv[])
{
	double* A;
	A = new double[10];
	MersenneTwisterGENERATOR* NumberGenerator;
	NumberGenerator = MersenneTwisterGENERATOR::getInstance();
	NumberGenerator->changeSeed(322);
	if (NULL == NumberGenerator)
	{
		return -1;
	}
	for (int i = 0; i <= 9; i++)
	{
		A[i] = NumberGenerator->getFloat();
	}

	term();

	return 0;
}

void term()
{
	MersenneTwisterGENERATOR* NumberGenerator = MersenneTwisterGENERATOR::getInstance();
	if (NULL != NumberGenerator)
	{
		// destroy singleton object
		NumberGenerator->release();
		NumberGenerator = NULL;
	}
}*/
