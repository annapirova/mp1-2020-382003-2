#include "line.h"


point::point(double x_, double y_)
{
	x = x_;
	y = y_;
}

point::point(const point& p2)
{
	x = p2.x;
	y = p2.y;
}

void point::Print()
{
	std::cout << "(" << x << ", " << y << ")";
}

std::ostream& operator<<(std::ostream& s, const point& p)
{
	s << "(" << p.x << ", " << p.y << ")";
	return s;
}

double GetDistance(const point& p1, const point& p2)
{
	return 0.0; // поправить
}

Line::Line(int np)
{
	nPoints = np;
	if (np > 0)
		points = new point[np];
	else
		points = nullptr;
	std::cout << np << " is alloceted\n";
}

// {20, 30, 40, 50} n = 4
Line::Line(double* coords, int n)
{
	n = n - n % 2; // (n / 2) * 2;
	nPoints = n / 2;
	points = new point[nPoints];
	for (int i = 0; i < n; i += 2)
	{
		points[i / 2].x = coords[i];
		points[i / 2].y = coords[i + 1];
	}
}

Line::Line(const Line& l2)
{
	nPoints = l2.nPoints;
	points = new point[nPoints];
	for (int i = 0; i < nPoints; i++)
	{
		points[i] = l2.points[i];
	}
}

// i = 0
//points[0].x = coords[0];
//points[0].y = coords[1];
//i = 2
//points[1].x = coords[2];
//points[1].y = coords[3];

Line::~Line()
{
	if (points != nullptr)
		delete[] points;
	std::cout << "Line delete\n";
}

void Line::Print() const
{
	for (int i = 0; i < nPoints; i++)
	{
		points[i].Print();
		std::cout << " -- ";
	}
	std::cout << "\n";
}

Line& Line::operator=(const Line& l2)
{
	if (this != &l2)
	{
		if (nPoints != l2.nPoints)
		{
			delete[] points;
			points = new point[l2.nPoints];
			nPoints = l2.nPoints;
		}
		for (int i = 0; i < nPoints; i++)
		{
			points[i] = l2.points[i];
		}
	}
	return *this;
}


// l1 + l2 --> l1.operator+(l2)
Line Line::operator+(const Line& l2) const
{
	Line res(nPoints + l2.nPoints);
	for (int i = 0; i < nPoints; i++)
		res.points[i] = points[i];
	for (int i = 0; i < l2.nPoints; i++)
		res.points[nPoints + i] = l2.points[i];
	return res;
}

point& Line::operator[](int i)
{
	point* x;
	if ((i >= 0) && (i < nPoints))
		return points[i];
	else
	{
		x = new point(); // утечка памяти
		return *x;
	}
}

std::ostream& operator<<(std::ostream& s, const Line& l2)
{
	for (int i = 0; i < l2.nPoints - 1; i++)
	{
		s << l2.points[i] << " -- ";
	}
	s << l2.points[l2.nPoints - 1];
	return s;
}

ClosedLine::ClosedLine(int np): Line(np + 1), isVisible(false)
{
}

ClosedLine::ClosedLine(double* coords, int n) : Line(n / 2 + 1), isVisible(false)
{
	for (int i = 0; i < n; i += 2)
	{
		points[i / 2].x = coords[i];
		points[i / 2].y = coords[i + 1];
	}
	points[n / 2].x = coords[0];
	points[n / 2].y = coords[1];
}

double Line::GetP() 
{
	return 0.0;
}

double ClosedLine::GetS()
{
	return 0.0;
}

void ClosedLine::Move(const point& newLeftPoint)
{
}


Rect::Rect(point leftPoint, point rightPoint) : ClosedLine(4)
{
	points[0] = leftPoint;
	points[1] = point(leftPoint.x, rightPoint.y);
	points[2] = rightPoint;
	points[3] = point(rightPoint.x, leftPoint.y);
	points[4] = points[0];
	std::cout << "rectangle was created\n";
}

Triangle::Triangle(point leftPoint, point rightPoint) : ClosedLine(3)
{
	std::cout << "triangle was created\n";
}
