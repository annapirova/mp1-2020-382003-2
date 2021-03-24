#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HeaderMG.h"

//����� ������
//������������ ��� ������� 
VEC::VEC(int n_) //����������� �� �����, �� ��������� n=1 ��� ������� 
     { n=n_;
       vec=new double[n];
	   memset(vec, 0, n*sizeof(double));  
     }     
     
VEC::VEC(const VEC& V) //����������� �� ��������� ��� ������� 
     { n=V.n;
       vec=new double[n];
       for(int i=0; i<n; i++)
       {vec[i]=V.vec[i];}
     }     
 
//�e��������� ��� �������    
VEC::~VEC()
     { delete[] vec;
     }

//���������� ����� ��� ������� 
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

//���������� �������� �������� ��� ������� 
VEC VEC::operator + (const VEC& V) const  //���������� ����� ��� ������� 
	{ int i, max, b;
	  
	  max=std::max(V.n,n);
	  VEC res(max);

	  for (i = 0; i < V.n; i++)
	  {res.vec[i]=V.vec[i];}
	  
	  for (i = 0; i < n; i++)
	  {res.vec[i]=res.vec[i]+vec[i];}
	  
	  return res;	  
	}

VEC VEC::operator * (double b) const  //���������� ��������� �� ����� ��� ������� 
{  	VEC res(n); 
	int i;
    for (i = 0; i < n; i++)
	{ if(vec[i]!=0)
	    {res.vec[i]=vec[i]*b;} 
	  
	}
      
	return res;
	}

//���������� ����� � ������ ��� ������� 
std::istream& operator>> (std::istream &is, VEC &V) //���� ��� ������� 
	 { int i;
	  
	   for (i = 0; i < V.n; i++)
	   { is>>V.vec[i];}
	   
      return is;
     }
     
std::ostream& operator<< (std::ostream &os, const VEC &V) //����� ��� ������� 
	 { int i;
	   for (i = 0; i < V.n; i++)
	   { os <<"\t"<<V.vec[i];}
	   os<<"\n";
	   return os;
    }

//��������� ���������� �������; 
void VEC::RAND(int a, int b)
  {  int i;
    // a=a*1000;
    // b=b*1000;
     for (i = 0; i < n; i++)
	   { vec[i]=rand()%(b-a+1)+a;
	     //vec[i]=vec[i]/1000;
		 }
   }   

//����� �������
//������������ ��� �������.
MAT::MAT(int n_) //����������� �� �����, �� ��������� n=1 ��� �������
     { int i;
	   n=n_;
       num=new VEC[n];
       VEC V(n);
       for(i=0;i<n;i++)
       {num[i]=VEC(n);}
     }     
    
MAT::MAT(const MAT& M) //����������� �� ��������� ��� �������
     { int i;
	   n=M.n;
       num=new VEC[n];
       for(i=0;i<n;i++)
       {num[i]=M.num[i];} 
     }     
 
//�e��������� ��� �������   
MAT::~MAT()
  {int i;
	 //for(i=0;i<n;i++)
     //{~VEC num[i];} //������ ������
	  delete[]num;
  }

//���������� ����� ��� ������� 
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

//���������� �������� �������� ��� �������
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

	   //std:: cout<< "\n\t������� ���������� ���������: ";
	 //  is>>M.n;

	 //  M = MAT(M.n);
	   
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
  
//��������� ���������� �������;
void MAT::RAND(int a, int b)
   { int i; 
     VEC A;
     for (i = 0; i < n; i++)
	 { num[i].RAND(a,b);
	 }
   }
	  
//����� ����� ������
//������������ ��� ������� 
MG::MG(int n_) //����������� �� ����� �������, �� ��������� n=1 ��� ������� 
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
    std::cout<<"\n������� ������� ���������: ";
	std::cin>>a>>b;
	Matrix().RAND(a,b);
    Vector_X().RAND(a,b);
    Vector_B()=Matrix()*Vector_X();
    flag=b-a;
}

void MG::DEC1()//������� ��� ��������� �����
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

void MG::DEC2()//������� "��� ����"
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

void MG::DEC3()//������� ��� ������� �����
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
 
void MG::DEC()//������� ����� ������
{
    
	if((flag+1)/2*n*n<550){DEC1();} else{
	if((flag+1)*(flag+1)>9000){DEC3();} else {DEC2();}}
}

//���������� ����� � ������ ��� ������� 
std::istream& operator>> (std::istream &is, MG &pop) //���� ������� ��� ������ ������ 
	 { is>>pop.Matrix();
       std::cout<<"\n\t������� ��������������� �������� �������: ";
       is>>pop.Vector_B();     
       return is;
     }
    
std::ostream& operator<< (std::ostream &os, const MG &pop) //����� ������� ��� �����a ������ 
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
	
	if(flag3==1){os<<"\n��� �������";}
	else{ if(flag2==1){os<<"\n����������� ��������� �������";}
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
      
	os<<"\n������ ������� X:\n";
	os<< pop.X;
	
	FAULT=FAULT+pop.X*(-1);
	os<<"\n����������� �������:\n";
	os<<FAULT;
	
	}	
	}
	
	return os;
    }
    
