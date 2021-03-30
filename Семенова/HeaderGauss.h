#include <iostream>

class VEC;
class MAT;

//����� ����� ������
class MG
{   public:
    int n;
    MAT* A;
    MAT& A_=*A;
    VEC* B;
    VEC& B_=*B;
    VEC* X;
    VEC& X_=*X;
    int flag=0;
    
public:
	//������������ ��� ������ ������ 
	MG(int n_=1);

	//�������� �������� �� ������ ��� ������ ������
	MAT& Matrix();
	VEC& Vector_B();
	VEC& Vector_X();
	
    //��������� ������� ��� ������ ������
	void RAND();
	
	//������� ��� ������ ������
	void DEC();
	
	//���������� ����� � ������ ��� ������� 
	friend std::istream& operator>> (std::istream &is, MG &pop);
	friend std::ostream& operator<< (std::ostream &os, const MG &pop);

};
