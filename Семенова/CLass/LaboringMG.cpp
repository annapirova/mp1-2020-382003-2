#include <iostream>
#include <locale>
#include <cstdlib>
#include "HeaderMG.h"
using namespace std;
int main()

{  setlocale(LC_ALL, "Rus");
   //srand(time(NULL));
   cout<<"МЕТОД ГАУССА\n\nВведите количество строк: ";
	
	int n, entry = 0, i, j, f, k;
	double con1, con2;
	cin>>n;
	MG pop(n);
	
    cout<<"1.Введение матрицы\n2.Заполнение матрицы рандомными числа\nВывод: ";
    cin>>entry;
    switch (entry)
    {case 1: cin>>pop;
             break;
     case 2: pop.RAND();
             break;
    }
   cout<<"\tМатрица:\n"<<pop.Matrix();
   if(entry==2){cout<<"\n\tВектор решений X':\n"<<pop.Vector_X();}
   cout<<"\n\tВектор значений B:\n"<<pop.Vector_B();
     
    pop.DEC();
	cout<<pop;

}

