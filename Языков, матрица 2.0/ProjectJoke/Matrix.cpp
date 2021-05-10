#include "Matrix.h"
#include<cmath>

Matrix::Matrix(int n, int rand_max = 100)
{
	this->rand_max = rand_max;
	sizematr = n;
	X.vect = new double[sizematr];
	X.sizematr = sizematr;
	b.vect = new double[sizematr];
	b.sizematr = sizematr;
	Solve.vect = new double[sizematr];
	Solve.sizematr = sizematr;
	b.init();

	matr_solution = new Vector[sizematr];
	matr = new Vector[sizematr];
	for (int i = 0; i < sizematr; i++)
	{
		Vector a(sizematr);
		matr[i] = a;//myVector(size);
		matr_solution[i] = a;
	}
}

Matrix::Matrix(const Matrix& m1)
{
	rand_max = m1.rand_max;
	sizematr = m1.sizematr;
	matr->~Vector();
	matr = new Vector[sizematr];
	for (int i = 0; i < sizematr; i++)
	{
		matr[i] = Vector(sizematr);
	}

	for (int i = 0; i < sizematr; i++)
	{
		matr[i] = m1.matr[i];
	}

}

Matrix::~Matrix()
{
	delete[] matr;
	matr = nullptr;
}

void Matrix::interface()
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
	int temp = 0;
	do {
		cout << "How to generate? (1 - manual, 2 - random generate):";
		cin >> temp;
		if (temp == 2)
		{
			generate();
		}
		else if (temp == 1)
		{
			hand_input();
		}
	} while (temp != 1 && temp != 2);

}


void Matrix::hand_input()
{
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "] ";
			cin >> matr[i][j];
			matr_solution[i][j] = matr[i][j];
		}
		cout << " = ";
		cin >> b[i];
	}
}

void Matrix::generate()
{
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			matr[i][j] = rand() % rand_max;
			matr_solution[i][j] = matr[i][j];
		}
	}
}

double& Matrix::operator()(int i, int j)
{
	return matr[i][j];
}

Matrix& Matrix::operator=(const Matrix& m2)
{
	if (this == &m2)
		return *this;
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			matr[i][j] = m2.matr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix &m2)
{
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			matr[i][j] += m2.matr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m2)
{
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			matr[i][j] -= m2.matr[i][j];
		}

	}return *this;
}

Matrix Matrix::operator+(const Matrix& m2)
{
	Matrix res(m2.sizematr);
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			res.matr[i][j] = matr[i][j] + m2.matr[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& m2)
{
	Matrix res(m2.sizematr);
	for (int i = 0; i < sizematr; i++)
	{
		for (int j = 0; j < sizematr; j++)
		{
			res.matr[i][j] = matr[i][j] - m2.matr[i][j];
		}
	}
	return res;
}

void Matrix::change_str(int i, int j)
{
	Vector temp(sizematr);
	for (int k = 0; k < sizematr; k++)
	{

		temp[k] = matr[i][k];
		matr[i][k] = matr[j][k];
		matr[j][k] = temp[k];
	}
}

ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	stream << "\t Matrix" << endl;
	for (int i = 0; i < matrix.sizematr; i++)
	{
		stream << matrix.matr[i] << "|" << matrix.b.vect[i] << endl;
	}
	return stream;
}

int Matrix::find_max_el(int i, int& str)
{
	int max_el = 1;
	for (int k = i + 1; k < sizematr; k++)
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
	cout << "\t*X*:    " << X << endl;
	cout << "inf = |x| < 1e-20" << endl;
}

void Matrix::solve()
{
	for (int i = 0; i < sizematr; i++)
	{
		Solve[i] = 0;
	}
	for (int i = 0; i < sizematr; i++)
		for (int j = 0; j < sizematr; j++)
			Solve[i] += matr_solution[i][j] * X[j];
	cout << "\t*Reverse*:   " << Solve << endl;
}
