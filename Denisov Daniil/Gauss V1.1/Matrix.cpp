#include "Matrix.h"
#include<cmath>

Matrix::Matrix(int n, int rand_max = 100)
{
  this->rand_max = rand_max;
  size = n;
  X.vect = new double[size];
  X.size = size;
  b.vect = new double[size];
  b.size = size;
  _solve.vect = new double[size];
  _solve.size = size;
  b.init();

  matr_solution = new myVector[size];
  matr = new myVector[size];
  for (int i = 0; i < size; i++)
  {
    myVector a(size);
    matr[i] = a;//myVector(size);
    matr_solution[i] = a;
  }
}

Matrix::Matrix(const Matrix& m1)
{
  rand_max = m1.rand_max;
  size = m1.size;
  matr->~myVector();
  matr = new myVector[size];
  for (int i = 0; i < size; i++)
  {
    matr[i] = myVector(size);
  }

  for (int i = 0; i < size; i++) 
  {
    matr[i] = m1.matr[i];
  }

}

Matrix::~Matrix()
{
  delete[] matr;
  matr = nullptr;
}

void Matrix:: interface()
{
  double _rand;
  cout << "What max rand element? ";
  cin >> _rand;
  rand_max = _rand;
  this->init();
  
  cout << *this;

}

void Matrix::init()
{
  int temp=0;
  do{
    cout << "How to generate a matrix??(1 - hand, 2 - random):";
    cin >> temp;
    if (temp == 2)
    {
     generate();
    }
    else if (temp == 1)
    {
      hand_init();
    }
  } while (temp != 1 && temp != 2);

}


  void Matrix::hand_init()
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        cout << "[" << i + 1 << "]" << "[" << j + 1 << "]";
        cin >> matr[i][j];
        matr_solution[i][j] = matr[i][j];
      }
      cout << " = ";
      cin >> b[i];
    }
  }

  void Matrix::generate()
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        matr[i][j] = rand() % rand_max;
        matr_solution[i][j] = matr[i][j];
      }
    }
  }

  double& Matrix::operator()(int i, int j)
  {
    // кинуть исключение
    return matr[i][j];
  }

  Matrix& Matrix::operator=(const Matrix& m2)
  {
    if (this == &m2)
      return *this;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        matr[i][j] = m2.matr[i][j];
      }
    }
    return *this;
  }

  Matrix& Matrix::operator+=(const Matrix &m2)
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        matr[i][j] += m2.matr[i][j];
      }
    }
    return *this;
  }

  Matrix& Matrix::operator-=(const Matrix& m2)
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        matr[i][j] -= m2.matr[i][j];
      }

    }return *this;
  }

  Matrix Matrix::operator+(const Matrix& m2)
  {
    Matrix res(m2.size);
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        res.matr[i][j] = matr[i][j]+ m2.matr[i][j];
      }
    }
    return res;
  }

  Matrix Matrix::operator-(const Matrix& m2)
  {
    Matrix res(m2.size);
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        res.matr[i][j] = matr[i][j] - m2.matr[i][j];
      }
    }
    return res;
  }

  void Matrix::change_str(int i, int j)
  {
    myVector temp(size);
    for (int k = 0; k < size; k++)
    {

      temp[k] = matr[i][k];
      matr[i][k] = matr[j][k];
      matr[j][k] = temp[k];
    }
  }

  ostream& operator<<(ostream& stream, const Matrix& matrix)
  {
    stream << "\t Matrix" << endl;
    for (int i = 0; i < matrix.size; i++)
    {
      stream << matrix.matr[i] << "|" << matrix.b.vect[i]<<endl;
    }
    return stream;
  }

  int Matrix::find_max_el(int i, int& str)
  {
    int max_el = 1;
    for (int k = i+1; k < size; k++)
    {
        if (abs(matr[k][i]) > max_el)
        {
          max_el = matr[k][i];
          str = k;
        }
    }
    return max_el;
  }

  void Matrix::print_X()
  {
    cout << "\t*******X*******"<<endl << "\t"<<X << endl;
    cout << "inf = |x| < 1e-20" << endl;
  }

  void Matrix::solve()
  {
    for (int i = 0; i < size; i++)
    {
      _solve[i] = 0;
    }
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
    _solve[i]+=matr_solution[i][j]*X[j];
    cout << "\t*******Reverse*******" << endl <<"\t"<< _solve << endl;
  }

