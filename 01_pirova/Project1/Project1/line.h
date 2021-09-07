#pragma once
#include <iostream>

struct point
{
	double x, y;

	point(double x_ = 0.0, double y_ = 0.0);
	point(const point& p2);
	void Print();

	friend std::ostream& operator<<(std::ostream& s, const point& p);
};

double GetDistance(const point& p1, const point& p2);

class Line
{
protected:
	int nPoints;
	point* points;
public:
	Line(int np = 0); // по умолчанию
	Line(double* coords, int n);
	Line(const Line& l2);
	~Line();

	void Print() const;

	Line& operator=(const Line& l2); 
	Line operator+(const Line& l2) const;
	//Line& operator+=(const Line& l2);
	friend std::ostream& operator<<(std::ostream& s, const Line& l2);
	point& operator[](int i);
};


class ClosedLine : public Line
{
public:
	ClosedLine(int np = 0);
	ClosedLine(double* coords, int n);
	~ClosedLine() 
	{
		std::cout << "ClosedLine delete\n";
	};

	double GetP();
	double GetS();
};

// сложение двух ClosedLine: 