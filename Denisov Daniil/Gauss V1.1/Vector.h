#ifndef _VECTOR_H
#define _VECTOR_H
#include<iostream>
#include<iomanip>
using namespace std;

class myVector
{
public:
  double* vect;
  int size;
   myVector(int n=1);//?
   myVector(const myVector& m2);
   ~myVector();
   void init();
   myVector& operator=(const myVector& v2);
   myVector& operator+=(const myVector& v2);
   myVector& operator-=(const myVector& v2);
   myVector operator+(const myVector& v2);
   myVector& operator*=(double k);
   myVector& operator/=(double k);
   double& operator[](int ind);
   void change_str(int i, int j);
   friend ostream& operator<<(ostream& stream, const myVector& vec);
   void leading_unit(int i);//Выделение ведущей единицы
};
#endif