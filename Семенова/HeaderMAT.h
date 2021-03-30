#include <iostream>

class VEC;

//����� �������
class MAT
{   
    int n;
    VEC* num;
    
public:
	//������������ 
	MAT(int n_=1);
	MAT(const MAT & M);
	
	//�e��������  
	~MAT();
	
	//�������� �������� �� ������ ��� �������
	int M_n() const;
	VEC* M_arr() const;
	
	//��������� ���������� �������;
	void RAND(int a=1, int b=100);
	
	//���������� �����
	MAT& operator = ( const MAT& M);
	
	//���������� �������� ��������
	VEC operator * (const VEC& V) const ;  //���������� ���������
	
	//���������� ����� � ������
	friend std::istream& operator>> (std::istream &is, MAT &M);
	friend std::ostream& operator<< (std::ostream &os, const MAT &M);
	friend class MG;
};

