#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderVEC.h"

//конструкторы 
VEC::VEC(int n_) //конструктор от длины вектора, по умолчанию n=1
     { n=n_;
       vec=new double[n];
	   memset(vec, 0, n*sizeof(double));  
     }     
     
VEC::VEC(const VEC& V) //конструктор от другого вектора
     { n=V.n;
       vec=new double[n];
       for(int i=0; i<n; i++)
       {vec[i]=V.vec[i];}
     }     
 
//деструктор     
VEC::~VEC()
     { delete[] vec;}

//передача значений по ссылке
int VEC::V_n() const
     { return n;} 

double* VEC::V_arr() const
     { return vec;} 

//Рандомное заполнение вектора; 
void VEC::RAND(int a, int b)
     { int i;
       a=a*1000;
       b=b*1000;
       for (i = 0; i < n; i++)
	   { vec[i]=rand()%(b-a+1)+a;
	     vec[i]=vec[i]/1000;
	   }
     } 
	
//перегрузка равно
VEC& VEC::operator = ( const VEC & V)  
     { int i;
	   if (this != &V)
	    { n=V.n;
	      delete []vec; 			 
	  	  vec=new double[n];
	      for (i = 0; i < n; i++)
	      { vec[i]=V.vec[i];}
	    }
 	   return *this;
	 }

//перегрузка бинарных операций
VEC VEC::operator + (const VEC& V) const  //перегрузка плюса
     { int i, max, b;
       max=std::max(V.n,n);
	   VEC res(max);
	   for (i = 0; i < V.n; i++)
	   { res.vec[i]=V.vec[i];}
   	   for (i = 0; i < n; i++)
	   {res.vec[i]=res.vec[i]+vec[i];}
	   return res;	  
	 }

VEC VEC::operator * (double b) const  //перегрузка умножения на число
     { VEC res(n); 
	   int i;
       for (i = 0; i < n; i++)
	   {res.vec[i]=vec[i]*b;}
       return res;
	 }

//перезрузка ввода и вывода для вектора 
std::istream& operator>> (std::istream &is, VEC &V) //ввод для вектора 
	 { int i;
	   for (i = 0; i < V.n; i++)
	   { is>>V.vec[i];}
       return is;
     }
     
std::ostream& operator<< (std::ostream &os, const VEC &V) //вывод для вектора 
	 { int i;
	   for (i = 0; i < V.n; i++)
	   { os <<"\t"<<V.vec[i];}
	   os<<"\n";
	   return os;
    }

