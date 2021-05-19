#include <iostream>
#include <string>
#include "MVector.h"
using namespace std;

int main()
{
	MVector<string> mas(3);

	//cout << "Film out BTS 2021" << '\n' << "Dynamite BTS 2020 " << '\n' << "Euphoria BTS 2018 " << '\n';

	mas[0] = "Film out BTS 2021";
	mas[1] = "Dynamite BTS 2020";
	mas[2] = "Euphoria BTS 2018";
	cout << mas << '\n';
	

	mas.push_back("Boy With luv BTS 2019");
	cout << "mas = " << mas << '\n';
}


