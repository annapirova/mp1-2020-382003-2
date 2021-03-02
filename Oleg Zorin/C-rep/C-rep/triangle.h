class Triangle
{
	double a, b, c;

public:	

	Triangle();
	Triangle(double a0, double b0, double c0);
	Triangle(const Triangle& c);
	~Triangle();

	double GetPer();
	double GetSqr();


};
