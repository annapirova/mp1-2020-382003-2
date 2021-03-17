#include <iostream>
class vector
{
	int size;
	double* value;
public:
	vector(int n = 1);
	vector(int n, double* v);
	vector(int n, int max);
	vector(const vector& v);
	~vector();
	vector& operator=(const vector& v);
	vector operator+(const vector& v) const;
	vector operator-(const vector& v);
	vector operator*(const vector& v);
	vector& operator-=(const vector& v);
	vector& operator+=(const vector& v);
	vector& operator*=(const vector& v);
	double& operator[](int i);
	friend std::ostream& operator<<(std::ostream& os, const vector& v);
};
