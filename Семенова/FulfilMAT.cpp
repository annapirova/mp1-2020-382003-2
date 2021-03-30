#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderMAT.h"
#include "HeaderVEC.h"

//����� �������
//������������ ��� �������.
MAT::MAT(int n_) //����������� �� �����, �� ��������� n=1 ��� �������.
     { int i;
	   n=n_;
       num=new VEC[n];
       VEC V(n);
       for(i=0;i<n;i++)
       {num[i]=V;}
     }     
    
MAT::MAT(const MAT& M) //����������� �� ������ �������
     { int i;
	   n=M.n;
       num=new VEC[n];
       for(i=0;i<n;i++)
       {num[i]=M.num[i];} 
     }     
 
//�e���������    
MAT::~MAT()
  {int i;
	  delete[]num;
  }
  
//�������� �������� �� ������
int MAT::M_n() const
     { return n;} 

VEC* MAT::M_arr() const
     { return num;} 

//��������� ���������� �������;
void MAT::RAND(int a, int b)
   { int i; 
     for (i = 0; i < n; i++)
	 { num[i].RAND(a,b);
	 }
   }

//���������� �����
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

//���������� �������� ��������
VEC MAT::operator * (const VEC& V) const  //���������� ��������� ��� �������
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

//���������� ����� � ������ ��� �������
std::istream& operator>> (std::istream &is, MAT &M) //���� ��� �������
	 { int i;	  			 
	   std:: cout<< "\t������� ��������������� �������� �������:\n";
	   for (i = 0; i < M.n; i++)
	   {  std:: cout<<"\t\t";
	      is>>M.num[i];}
       return is;
     }
    
std::ostream& operator<< (std::ostream &os, const MAT &M) //����� ��� �������
	 { int i;
	   for (i = 0; i < M.n; i++)
	   { os <<M.num[i];}
	   return os;
    }
    
    

