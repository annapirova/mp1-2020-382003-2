#include <iostream>
#include <locale>
#include <cstdlib>
#include "HeaderMG.h"
using namespace std;
int main()

{  setlocale(LC_ALL, "Rus");
   //srand(time(NULL));
   cout<<"����� ������\n\n������� ���������� �����: ";
	
	int n, entry = 0, i, j, f, k;
	double con1, con2;
	cin>>n;
	MG pop(n);
	
    cout<<"1.�������� �������\n2.���������� ������� ���������� �����\n�����: ";
    cin>>entry;
    switch (entry)
    {case 1: cin>>pop;
             break;
     case 2: pop.RAND();
             break;
    }
   cout<<"\t�������:\n"<<pop.Matrix();
   if(entry==2){cout<<"\n\t������ ������� X':\n"<<pop.Vector_X();}
   cout<<"\n\t������ �������� B:\n"<<pop.Vector_B();
     
    pop.DEC();
	cout<<pop;

}

