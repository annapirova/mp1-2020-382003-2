class Complex
{
	double Re, Im;

public:
	Complex();
	Complex(double Re, double Im);
	Complex(const Complex& z);

	Complex& operator=(const Complex& other);
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);

	void Print();
};