#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderMAT.h"
#include "HeaderVEC.h"
#include "HeaderGauss.h"
//КЛАСС МЕТОД ГАУССА
//конструкторы для вектора 
MG::MG(int n_) //конструктор от длины , по умолчанию n=1 для Метода Гаусса 
     { n=n_;
       A=new MAT(n);
	   B=new VEC(n);
	   X=new VEC(n); 
     } 
   
//передача значений по ссылке для метода Гаусса 
MAT& MG::Matrix() 
{ return *A;} 

VEC& MG::Vector_B()
{ return *B;}

VEC& MG::Vector_X()
{ return *X;}

//Рандомное задание для Метода Гаусса
void MG::RAND()
{   int a,b;
    std::cout<<"\nВведите границы диапозона: ";
	std::cin>>a>>b;
	(*A).RAND(a,b);
    (*X).RAND(a,b);
    (*B)=(*A)*(*X);
    flag=b-a;
}

//Решение для Метода Гаусса
void MG::DEC()
{ int i,j,f,k; int max, i_max, non_i;
  double con1, con2; 
  
  int non [n];
  for(i=0;i<n;i++)
  { non[i]=-1;}
   
  for(i=0;i<n;i++)
  {   max=0;
	  i_max=-1;
	  
	  for(j=0;j<n;j++)
	  { if(non[j]==-1){
	    if((*A).num[j].vec[i]*(*A).num[j].vec[i]>max)
	    { max=(*A).num[j].vec[i]*(*A).num[j].vec[i];
	      i_max=j;}
	    }
	  }
	  non[i_max]=0;
	  
      if((*A).num[i_max].vec[i]!=0)
	  { for(f=0;f<n;f++)
	    { if(f!=i_max){
		  con1=(*A).num[i_max].vec[i];
		  if((*A).num[f].vec[i]!=0)
	      { con1=(*A).num[f].vec[i]/con1;
	        (*A).num[f]=(*A).num[f]+((*A).num[i_max]*con1*(-1));
			(*B).vec[f]= (*B).vec[f]- (*B).vec[i_max]*con1;
		  } }
	    }
	  } 
	}
	
}


//перезрузка ввода и вывода для вектора 
std::istream& operator>> (std::istream &is, MG &pop) //ввод вектора для метода Гаусса 
	 { is>>*(pop.A);
       std::cout<<"\n\tВведите последовательно элементы вектора: ";
       is>>*(pop.B);     
       return is;
     }
  
std::ostream& operator<< (std::ostream &os, const MG &pop) //вывод вектора для Методa Гаусса 
 {  
   int i,j,f, n;
   int flag1=0, flag2=0, flag3=0;
   double con1;
   
   MAT& M=*(pop.A);
   VEC& V=*(pop.B);
   VEC& X=*(pop.X);
   
   n=pop.n;	
   for(i=n-1;i>=0;i--)
    { for(j=0;j<n;j++)
      { if(M.M_arr()[i].V_arr()[j]!=0){flag1=1;}}
        if((flag1==0)&&(V.V_arr()[i]!=0)){ flag3=1;}
	    if((flag1==0)&&(V.V_arr()[i]==0)){ flag2=1;} 
	}
	
	if(flag3==1){os<<"\nНет решения";}
	else{ if(flag2==1){os<<"\nБесконечное множество решений";}
	else{ 
	
	VEC FAULT(X);
	
	for(i=0;i<n;i++)
	{ j=0;
	  while((M.M_arr()[i].V_arr()[j]==0)&&(j<n))
      { j++;}
	  X.V_arr()[j]=V.V_arr()[i]/M.M_arr()[i].V_arr()[j];	  
	}
      
	os<<"\nВектор решений X:\n";
	os<< X;
	if(pop.flag!=0){
	FAULT=FAULT+X*(-1);
	os<<"\nПогрешность решения:\n";
	os<<FAULT;}
    }
	}	
	return os;
    }
  
