#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderMG.h"

//КЛАСС ВЕКТОР
//конструкторы для вектора 
VEC::VEC(int n_) //конструктор от длины, по умолчанию n=1 для вектора 
     { n=n_;
       vec=new double[n];
	   memset(vec, 0, n*sizeof(double));  
     }     
     
VEC::VEC(const VEC& V) //конструктор от референса для вектора 
     { n=V.n;
       vec=new double[n];
       for(int i=0; i<n; i++)
       {vec[i]=V.vec[i];}
     }     
 
//дeсструктор для вектора    
VEC::~VEC()
     { delete[] vec;
     }

//перегрузка равно для вектора 
VEC& VEC::operator = ( const VEC & V)  
   {  int i;
	  if (this != &V)
	  {   n=V.n;
	      delete []vec; 			 
	  	  vec=new double[n];
	  	  
	   for (i = 0; i < n; i++)
	   { vec[i]=V.vec[i];}
	   }
 	  return *this;
	}

//перегрузка бинарных операций для вектора 
VEC VEC::operator + (const VEC& V) const  //перегрузка плюса для вектора 
	{ int i, max, b;
	  
	  max=std::max(V.n,n);
	  VEC res(max);

	  for (i = 0; i < V.n; i++)
	  {res.vec[i]=V.vec[i];}
	  
	  for (i = 0; i < n; i++)
	  {res.vec[i]=res.vec[i]+vec[i];}
	  
	  return res;	  
	}

VEC VEC::operator * (double b) const  //перегрузка умножения на число для вектора 
{  	VEC res(n); 
	int i;
    for (i = 0; i < n; i++)
	{ if(vec[i]!=0)
	    {res.vec[i]=vec[i]*b;} 
	  
	}
      
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

//Рандомное заполнение вектора; 
void VEC::RAND(int a, int b)
  {  int i;
    // a=a*1000;
    // b=b*1000;
     for (i = 0; i < n; i++)
	   { vec[i]=rand()%(b-a+1)+a;
	     //vec[i]=vec[i]/1000;
		 }
   }   

//КЛАСС МАТРИЦА
//конструкторы для матрицы.
MAT::MAT(int n_) //конструктор от длины, по умолчанию n=1 для матрицы
     { int i;
	   n=n_;
       num=new VEC[n];
       VEC V(n);
       for(i=0;i<n;i++)
       {num[i]=VEC(n);}
     }     
    
MAT::MAT(const MAT& M) //конструктор от референса для матрицы
     { int i;
	   n=M.n;
       num=new VEC[n];
       for(i=0;i<n;i++)
       {num[i]=M.num[i];} 
     }     
 
//дeсструктор для матрицы   
MAT::~MAT()
  {int i;
	 //for(i=0;i<n;i++)
     //{~VEC num[i];} //потеря памяти
	  delete[]num;
  }

//перегрузка равно для матрицы 
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

//перегрузка бинарных операций для матрицы
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

	   //std:: cout<< "\n\tВведите количество элементов: ";
	 //  is>>M.n;

	 //  M = MAT(M.n);
	   
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
  
//Рандомное заполнение матрицы;
void MAT::RAND(int a, int b)
   { int i; 
     VEC A;
     for (i = 0; i < n; i++)
	 { num[i].RAND(a,b);
	 }
   }
	  
//КЛАСС МЕТОД ГАУССА
//конструкторы для вектора 
MG::MG(int n_) //конструктор от длины вектора, по умолчанию n=1 для вектора 
     { n=n_;
       A=MAT(n);
	   B=VEC(n);
	   X=VEC(n); 
     } 

MAT& MG::Matrix()
{ return A;} 

VEC& MG::Vector_B()
{ return B;}

VEC& MG::Vector_X()
{ return X;}

void MG::RAND()
{   int a,b;
    std::cout<<"\nВведите границы диапозона: ";
	std::cin>>a>>b;
	Matrix().RAND(a,b);
    Vector_X().RAND(a,b);
    Vector_B()=Matrix()*Vector_X();
    flag=b-a;
}

void MG::DEC1()//решение для маленьких чисел
{ int i,j,f,k;
  double con1, con2; 
	VEC C1;
    for(i=0;i<n-1;i++)
    { j=0;
	  C1=Matrix().num[i];
	  while((C1.vec[j]==0)&&(j<n))
      { j++;}
      if(j<n)
	  { for(f=i+1;f<n;f++)
	    { con1=Matrix().num[i].vec[j];
		  if(Matrix().num[f].vec[j]!=0)
	      { con2=Matrix().num[f].vec[j];
	        
	        Matrix().num[f]=Matrix().num[f]*con1+(Matrix().num[i]*con2*(-1));
			Vector_B().vec[f]= Vector_B().vec[f]*con1- Vector_B().vec[i]*con2;

		  } 
	    } 
	  }
	}
}

void MG::DEC2()//решение "как надо"
{ int i,j,f,k;
  double con1, con2; 
	VEC C1;
    for(i=0;i<n-1;i++)
    { j=0;
	  C1=Matrix().num[i];
	  while((C1.vec[j]==0)&&(j<n))
      { j++;}
      if(j<n)
	  { for(f=i+1;f<n;f++)
	    { con1=Matrix().num[i].vec[j];
		  if(Matrix().num[f].vec[j]!=0)
	      { con1=Matrix().num[f].vec[j]/con1;
	        Matrix().num[f]=Matrix().num[f]+(Matrix().num[i]*con1*(-1));
			Vector_B().vec[f]= Vector_B().vec[f]- Vector_B().vec[i]*con1;
		  } 
	    }
	  }
	}
}

void MG::DEC3()//решение для больших чисел
{ int i,j,f,k;
  double con1, con2; 
	VEC C1;
    for(i=0;i<n-1;i++)
    { j=0;
	  C1=Matrix().num[i];
	  while((C1.vec[j]==0)&&(j<n))
      { j++;}
      if(j<n)
	  { 
	    con1=1/Matrix().num[i].vec[j];
	    Matrix().num[i]=Matrix().num[i]*con1;
	    Vector_B().vec[i]= Vector_B().vec[i]*con1;
	    for(f=i+1;f<n;f++)
	    { if(Matrix().num[f].vec[j]!=0)
	      {con2=Matrix().num[f].vec[j];
	       Matrix().num[f]=Matrix().num[f]+((Matrix().num[i]*con2)*(-1));
	       Vector_B().vec[f]= Vector_B().vec[f]- Vector_B().vec[i]*con2;
		  } 
	    }
	  }
	 }
}
 
void MG::DEC()//решение Метод Гаусса
{
    
	if((flag+1)/2*n*n<550){DEC1();} else{
	if((flag+1)*(flag+1)>9000){DEC3();} else {DEC2();}}
}

//перезрузка ввода и вывода для вектора 
std::istream& operator>> (std::istream &is, MG &pop) //ввод вектора для метода Гаусса 
	 { is>>pop.Matrix();
       std::cout<<"\n\tВведите последовательно элементы вектора: ";
       is>>pop.Vector_B();     
       return is;
     }
    
std::ostream& operator<< (std::ostream &os, const MG &pop) //вывод вектора для Методa Гаусса 
	  { int i,j,f, n;
	    int flag1=0, flag2=0, flag3=0;
	    double con1;
	    n=pop.n;	
	for(i=n-1;i>=0;i--)
    { for(j=0;j<n;j++)
      { if(pop.A.num[i].vec[j]!=0){flag1=1;}}
      if((flag1==0)&&(pop.B.vec[i]!=0)){ flag3=1;}
	  if((flag1==0)&&(pop.B.vec[i]==0)){ flag2=1;} 
	  
	}
	
	if(flag3==1){os<<"\nНет решения";}
	else{ if(flag2==1){os<<"\nБесконечное множество решений";}
	else{ 
	
	int q;
	MAT M1(pop.A);
	VEC V1(pop.B);
	VEC FAULT(pop.X);
	
	for(i=n-1;i>=0;i--)
    { q=-1; j=0;
	  while(q==-1)
      {if(pop.A.num[i].vec[j]!=0){q=j;} j++;}
      pop.X.vec[i]= V1.vec[i]/M1.num[i].vec[q];
      con1=pop.X.vec[i];
      for(f=i-1;f>=0;f--)
      { V1.vec[f]=V1.vec[f]-M1.num[f].vec[q]*con1;
        M1.num[f].vec[q]=0;
	  } 
	}
      
	os<<"\nВектор решений X:\n";
	os<< pop.X;
	
	FAULT=FAULT+pop.X*(-1);
	os<<"\nПогрешность решения:\n";
	os<<FAULT;
	
	}	
	}
	
	return os;
    }
    
