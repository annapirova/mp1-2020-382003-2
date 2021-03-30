#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderMAT.h"
#include "HeaderVEC.h"

//КЛАСС МАТРИЦА
//конструкторы для матрицы.
MAT::MAT(int n_) //конструктор от длины, по умолчанию n=1 для матрицы.
     { int i;
	   n=n_;
       num=new VEC[n];
       VEC V(n);
       for(i=0;i<n;i++)
       {num[i]=V;}
     }     
    
MAT::MAT(const MAT& M) //конструктор от другой матрицы
     { int i;
	   n=M.n;
       num=new VEC[n];
       for(i=0;i<n;i++)
       {num[i]=M.num[i];} 
     }     
 
//дeсструктор    
MAT::~MAT()
  {int i;
	  delete[]num;
  }
  
//передача значений по ссылке
int MAT::M_n() const
     { return n;} 

VEC* MAT::M_arr() const
     { return num;} 

//Рандомное заполнение матрицы;
void MAT::RAND(int a, int b)
   { int i; 
     for (i = 0; i < n; i++)
	 { num[i].RAND(a,b);
	 }
   }

//перегрузка равно
MAT& MAT::operator = ( const MAT & M)  
   {  int i;
	  if (this != &M)
	  {   n=M.n;
	      num=new VEC[n];
	      
       for(i=0;i<n;i++)
       {num[i]=M.num[i];} 
      }
 	  return *this;
	}

//перегрузка бинарных операций
VEC MAT::operator * (const VEC& V) const  //перегрузка умножения для матрицы
	{ int i, j, e, min;
	  VEC res(n);
      VEC A(n);
	 //std::cout<<res;
	  for (i = 0; i < V.n; i++)
	  { for(j=0; j<n; j++)
	    {  A=num[i];
		   res.vec[i]= res.vec[i]+A.vec[j]*V.vec[j];}
      }
	  /*for (i = 0; i < n; i++)
	  {res.vec[i]=res.vec[i]+vec[i];}*/
	  
	  return res;	  
	}

//перезрузка ввода и вывода для матрицы
std::istream& operator>> (std::istream &is, MAT &M) //ввод для матрицы
	 { int i;	  			 
	   std:: cout<< "\tВведите последовательно элементы матрицы:\n";
	   for (i = 0; i < M.n; i++)
	   {  std:: cout<<"\t\t";
	      is>>M.num[i];}
       return is;
     }
    
std::ostream& operator<< (std::ostream &os, const MAT &M) //вывод для матрицы
	 { int i;
	   for (i = 0; i < M.n; i++)
	   { os <<M.num[i];}
	   return os;
    }
    
    

