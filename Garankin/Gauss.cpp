#include "Gauss.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void Gauss::Print()
{
	cout << "Ваша матрица: \n";
	for (int i = 0; i < size; i++)
	{
		cout << "|";
		for (int j = 0; j < size; j++)
		{
			cout << MatA[i][j] << "\t\t";
		}
		cout << "|";
		cout << VecB[i];
		cout << "|\n";
	}
}


void Gauss::HandInput()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> MatA[i][j];
		}
	}
}


void Gauss::GeneratorSystem()
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			MatA[i][j] = rand() % 10;
		}
		MatA[i][i] *= 10.0;
	}

	//VecX.GeneratorSystem(size);
	//VecB = MatA * VecX;
	//VecX.Clean();

	VecB.GeneratorSystem(size);
}


Vector Gauss:: gauss()
{
	for (int k = 0; k < size; k++)
	{
		double T = MatA[k][k];
		for (int j = size; j >= k; j--)
		{
			MatA[k][j] /= T;
		}
		for (int j = k + 1; j <size; j++)
		{
			T = MatA[j][k];
			for (int l = size; l >= k; l--)
			{
				MatA[j][l] -= MatA[k][l] * T;
				VecB[j] -= VecB[k] * T;
			}
		}
	}
	
	VecX[size - 1] = VecB[size - 1];//MatA[size - 1][size];
	for (int i = size - 2; i >= 0; i--)
	{
		VecX[i] = VecB[i];
		for (int j = i + 1; j < size; j++) {
			VecX[i] = VecX[i] - MatA[i][j] * VecX[j];
		}
	}

	return 0;
}

bool Gauss::Check()
{
	Vector temp = MatA * VecX - CB;
	double max = fabs(temp.Vec[0]);
	for (int i = 0; i < size; i++)
	{
		if (fabs(temp.Vec[i]) > max)
			max = fabs(temp.Vec[i]);
	}
	if (max < exp(-10))
	{
		cout<<"true";
		return true;
	}
	else
	{
		cout<<"false";
		return false;
	}
}
