#include <iostream>
#ifndef HEADERVEC_H
#define HEADERVEC_H

//����� ������
class VEC
{   public:
    int n;
    double* vec;
    
public:
	//������������ ��� ������� 
	VEC(int n_=1);
	VEC(const VEC & V);

	//�e�������� ��� ������� 
	~VEC();
	
	//���������� ����� ��� ������� 
	VEC& operator = ( const VEC& V);
	
	//���������� �������� �������� ��� ������� 
	VEC operator + (const VEC& V) const ;  //���������� ����� ��� ������� 
	VEC operator * (double n) const ; //���������� ��������� �� ����� ��� ������� 
	
	//���������� ����� � ������ ��� ������� 
	friend std::istream& operator>> (std::istream &is, VEC &V);
	friend std::ostream& operator<< (std::ostream &os, const VEC &V);
	
	//��������� ���������� �������;
	void RAND(int a=1, int b=100);
	
//	friend class MAT;
//	friend class MG;
};


//����� �������
class MAT
{   
    public:
    int n;
    VEC* num;
    
public:
	//������������ ��� �������
	MAT(int n_=1);
	MAT(const MAT & M);
	
	//�e�������� ��� ������� 
	~MAT();
	
	//���������� ����� ��� �������
	MAT& operator = ( const MAT& M);
	
	//���������� �������� �������� ��� �������
	VEC operator * (const VEC& V) const ;  //���������� ��������� ��� �������
	
	//���������� ����� � ������ ��� �������
	friend std::istream& operator>> (std::istream &is, MAT &M);
	friend std::ostream& operator<< (std::ostream &os, const MAT &M);
	
	//��������� ���������� �������;
	void RAND(int a=1, int b=100);
//	friend class MG;
};


//����� ����� ������
class MG
{   //public:
    int n;
    MAT A;
    VEC B;
    VEC X;
    int flag=0;
    
public:
	//������������ ��� ������� 
	MG(int n_=1);
//	VEC(const VEC & V);
	
	MAT& Matrix();
	VEC& Vector_B();
	VEC& Vector_X();
	void RAND();
	
	void DEC();
	void DEC1();
	void DEC2();
	void DEC3();
	
/*	//���������� ����� ��� ������� 
	VEC& operator = ( const VEC& V);
	
	//���������� �������� �������� ��� ������� 
	VEC operator + (const VEC& V) const ;  //���������� ����� ��� ������� 
	VEC operator * (double n) const ; //���������� ��������� �� ����� ��� ������� 
*/	
	//���������� ����� � ������ ��� ������� 
	friend std::istream& operator>> (std::istream &is, MG &pop);
	friend std::ostream& operator<< (std::ostream &os, const MG &pop);
	
	//void RAND();
};
#endif
