#include "Vector.h"
const int _RAND_MAX=500;
myVector::myVector(int n)
{
  try
  {
    size = n;
    vect = new double[size];
  }
  catch (...)
  {
    cout << "Vector is NOT CREATED!!!" << endl;
  }
}

myVector::myVector(const myVector& v2)
{
  size = v2.size;
  vect = new double[size];
  for (int i = 0; i < size; i++) {
    vect[i] = v2.vect[i];
  }
}

myVector::~myVector()
{
  delete[] vect;
  vect = nullptr;
}

void myVector::init()
{
  for (int i = 0; i < size; i++)
  {
    vect[i] = rand() % _RAND_MAX;
  }
}

myVector& myVector::operator=(const myVector& v2)
{
  if (this == &v2)
    return *this;
  delete[] vect;
  vect = new double[v2.size];
  size = v2.size;
  for (int i = 0; i < size; i++) {
    vect[i] = v2.vect[i];
  }
  return *this;
}

myVector& myVector::operator+=(const myVector& v2)
{
  for (int i = 0; i < size; i++)
  {
    vect[i] += v2.vect[i];
  }
  return *this;
}

myVector& myVector::operator-=(const myVector& v2)
{
  for (int i = 0; i < size; i++)
  {
    vect[i] -= v2.vect[i];
  }
  return *this;
}

myVector myVector::operator+(const myVector& v2)
{
  myVector new_vector(v2.size);
  for (int i = 0; i < size; i++)
  {
    new_vector.vect[i] = vect[i] + v2.vect[i];
  }
  return new_vector;
}

myVector& myVector::operator*=(double k)
{
  for (int i = 0; i < size; i++)
  {
    vect[i] *= k;
  }
  return *this;
}

myVector& myVector::operator/=(double k)
{
  for (int i = 0; i < size; i++)
  {
    vect[i] /= k;
  }
  return *this;
}

double& myVector::operator[](int ind)
{
  if (ind > size)
    throw std::exception();
  return vect[ind];
}

void myVector::change_str(int i, int j)
{
  bool error = false;
  if (i >= size || i < 0 || j >= size || j < 0 || j < i)
  {
    error = true;
  }

  if (!error)
  {
    double temp = vect[i];
    vect[i] = vect[j];
    vect[j] = temp;
  }
}

ostream& operator<<(ostream& stream, const myVector& vec)
{
  for (int i = 0; i < vec.size;  i++) {
    stream << vec.vect[i]<<setfill('_') << setw(12);
  }
  return stream;
}

void myVector::leading_unit(int i)
{
  int temp = vect[i];
  for (int k = 0; k < size; k++)
  {
    vect[k] /= temp;
  }
  //b[i] /= temp;
}
