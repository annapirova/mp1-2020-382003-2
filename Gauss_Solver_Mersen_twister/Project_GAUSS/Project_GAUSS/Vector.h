#pragma once
#include "Header.h"

class vector
{
	ERRORS W;
	int size;
	double* value;
public:
	void RANDOM(int argc, double* b);
	void term();
	vector(int n = 1);
	vector(int n, double* v);
	vector(int n, int max);
	vector(const vector& v);
	~vector();
	void swap(int a, int b);
	vector& operator=(const vector& v);
	vector operator+(const vector& v) const;
	vector operator-(const vector& v) const;
	vector& operator-=(const vector& v);
	vector& operator+=(const vector& v);
	friend vector operator*(double p, const vector& v);
	friend vector operator*(const vector& v, double p);
	double& operator[](int i);
	const double& operator[](int i) const;
	bool operator==(const vector& v) const;
	int GetSize() const;
	friend std::ostream& operator<<(std::ostream& os, const vector& v);
	friend std::istream& operator >> (std::istream& is, const vector& v);
	friend class Solver;
};