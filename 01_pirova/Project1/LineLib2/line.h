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
	int color;
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
protected: 
	int colorFill;
public:
	ClosedLine(int np = 0);
	ClosedLine(double* coords, int n);
	virtual ~ClosedLine() 
	{
		std::cout << "ClosedLine delete\n";
	};

	virtual void Resize(int side, const point& newPoint) = 0;
	//{
	//	std::cout << "ClosedLine resize\n";
	//};

	double GetP();
	double GetS();
};

class Trap : public ClosedLine
{
public:
	Trap(const point& pLeft, const point& pRight);
	void Resize(int side, const point& newPoint);
	virtual ~Trap() 
	{
		std::cout << "Trap delete\n";
	}
};

class Triangle : public ClosedLine
{
public:
	Triangle(const point& pLeft, const point& pRight);
	void Resize(int side, const point& newPoint);
	virtual ~Triangle()
	{
		std::cout << "Triangle delete\n";
	}
};