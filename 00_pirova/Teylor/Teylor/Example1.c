#include "stdio.h"
#include "math.h"

typedef double (*Function)(double);

typedef double (*Function2d)(double, double);


double Sqr(double x)
{
	return x * x;
}

double Log(double x)
{
	return log(1.0+x);
}

double Sqrt(double x)
{
	if (x < 0)
		return 0.0;
	else
		return sqrt(x);
}

void Print(double x1, double x2)
{
	double step = (x2 - x1) / 10.0;
	double y = x1;
	//[x1, x2] шаг step;
	while (y < x2 + step)
	{
		printf("f(%.3lf) = %.3lf\n", y, Sqr(y));
		y += step;
	}
	printf("\n");
}

void Print2(double x1, double x2, Function f)
{
	double step = (x2 - x1) / 10.0;
	double y = x1;
	//[x1, x2] шаг step;
	while (y <= x2)
	{
		printf("f(%.3lf) = %.3lf\n", y, f(y));
		y += step;
	}
	printf("\n");
}

double Parabola(double x, double y)
{
	return x * x + y * y + 5.0;
}

void Print2d(double x1, double x2, 
	double y1, double y2, 
	Function2d f)
{
	double stepX = (x2 - x1) / 10.0;
	double y = x1;
	double stepY = (y2 - y1) / 10.0;
	double yy = y1;

	//[x1, x2] шаг step;
	while (y <= x2)
	{
		yy = y1;
		while (yy <= y2)
		{
			printf("%6.3lf\t", f(y, yy));
			yy += stepY;
		}
		y += stepX;
		printf("\n");
	}
	printf("\n");
}

void main()
{
	Function f2 = Sqrt;
	Function funcs[3] = { Sqr, Log, f2 };
	int i;
	//Print(1.0, 2.0);
	//Print2(1.0, 2.0, Sqr);
	//Print2(1.0, 2.0, Log);
	//Print2(1.0, 2.0, f2);

	//for (i = 0; i < 3; i++)
	//{
	//	Print2(1.0, 2.0, funcs[i]);
	//}

	Print2d(-3.0, -2.0, 1.0, 2.0, Parabola);
}