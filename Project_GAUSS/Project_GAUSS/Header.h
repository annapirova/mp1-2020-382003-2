#pragma once
#include <locale>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum ERRORS
{
	SUCCESS, //0
	ERROR_N_NOT_EQUAL_M,//1
	ERROR_Aij_EQUAL_ZERO_BUT_bij_NOT,//2
	ERROR_Aij_EQUAL_ZERO_AND_bij_EQUAL_ZERO,
	ERROR_ACCURACY_COMPUTING, //3
	ERROR_INSERT,//4
	ERROR_MENU,//5
	ERROR_INSERT_SIZES,//6
	//ERROR_FREE_VECTOR_B

};

#define EPS 1e-10