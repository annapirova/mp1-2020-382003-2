class Complex
{
public:
	double a, b;

	Complex();
	Complex(double a, double b);
	Complex(const Complex& z);
	
	void Print();
	void Add(Complex z1, Complex z2);
	void Sub(Complex z1, Complex z2);
	void Mult(Complex z1, Complex z2);
	void Div(Complex z1, Complex z2);
};