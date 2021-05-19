#pragma oncearr
#include <iostream>
using namespace std;

template <class T>
class MVector 
{
private:
	int n;
	T* mas;
public:
	MVector(int _n = 3); //конструктор
	MVector(const MVector& vec); //копирование
	~MVector();// деструктор
	

	int get_size() const;
	void resize(int _n);
	void push_back(const T& el); 

	MVector& operator=(const MVector& vec);
	T& operator[](int i); friend istream& operator>>(istream& is, MVector<T>& vec) 
	{
		for (int i = 0; i < vec.n; i++) 
		{
			is >> vec.mas[i];
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const MVector<T>& vec) 
	{
		os << '(';
		for (int i = 0; i < vec.n - 1; i++)
		{
			os << vec.mas[i] << ", ";
		}
		os << vec.mas[vec.n - 1] << ')';
		return os;
	}
};

template <class T>
MVector<T>::MVector(int _n) 
{
	if (_n > 0) 
	{
		n = _n;
		mas = new T[n];
	}
	else 
	{
		cout << "Non-positive value\n";
	}
}

template <class T>
MVector<T>::MVector(const MVector& vec) 
{
	n = vec.n;
	mas = new T[vec.n];
	for (int i = 0; i < n; i++) 
	{
		mas[i] = vec.mas[i];
	}
}

template <class T>
MVector<T>::~MVector()
{
	delete[] mas;
}



template <class T>
int MVector<T>::get_size() const
{
	return n;
}

template <class T>
void MVector<T>::resize(int _n) // изменение размпра массива для push.back'а
{
	if (_n == n) 
	{
		return;
	}

	T* New_mas = new T[_n];

	if (_n > n) 
	{
		for (int i = 0; i < n; i++) 
		{
			New_mas[i] = mas[i];
		}
	}
	else 
	{
		for (int i = 0; i < _n; i++) 
		{
			New_mas[i] = mas[i];
		}
	}

	delete[] mas;
	mas = New_mas;
	n = _n;
}

template <class T>
MVector<T>& MVector<T>::operator=(const MVector<T>& vec) //=
{
	if (this == &vec) 
	{
		return *this;
	}
	if (vec.n != n) 
	{
		delete[] mas;
		n = vec.n;
		mas = new T[n];
	}
	for (int i = 0; i < n; i++) 
	{
		mas[i] = vec.mas[i];
	}
	return *this;
}

template <class T>
T& MVector<T>::operator[](int i)  //[]
{
	if (i >= 0 && i < n) 
	{
		return mas[i];
	}
	else 
	{
		cout << "Warning index\n";
	}
}

template <class T>
void MVector<T>::push_back(const T& elem) // добавление элемента к существующему вектору в конце
{
	int New_n = n + 1;
	T* New_mas = new T[New_n];
	for (int i = 0; i < n; i++) 
	{
		New_mas[i] = mas[i];
	}
	New_mas[n] = elem;

	delete[] mas;
	mas = New_mas;
	n = New_n;
}