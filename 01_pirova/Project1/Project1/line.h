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
	int color;
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
	
	double GetP();
};


class ClosedLine : public Line
{
	int colorFill;
	bool isVisible;
public:
	ClosedLine(int np = 0);
	ClosedLine(double* coords, int n);
	~ClosedLine() 
	{
		std::cout << "ClosedLine delete\n";
	};

	//ClosedLine(point leftPoint, point rightPoint);

	double GetS();

	void Move(const point& newLeftPoint);
	virtual void Resize(int side, double diff) 
	{
		std::cout << "ClosedLine Resize\n";
	};

	void Show() 
	{
		isVisible = true;
	};
	void Hide()
	{
		isVisible = false;
	}
};

class Rect : public ClosedLine
{
public:
	Rect(point leftPoint, point rightPoint);
	~Rect() {};
	// up or down
	// 1 - up
	// 2 - to right
	void Resize(int side, double diff)
	{
		std::cout << "Rect Resize\n";
		// calculate coords
	}
};

class Triangle : public ClosedLine
{
public:
	Triangle(point leftPoint, point rightPoint);
	
	// up or down
	void Resize(int side, double diff)
	{
		std::cout << "Triangle Resize\n";
		// calculate coords
	}

	~Triangle() {};
};