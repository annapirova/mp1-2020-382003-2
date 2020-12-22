#include "stdio.h"
#include "locale.h"
#include "math.h"

double EPS = 1e-10;

void main()
{
	int i;
	double A[10];
	double rmin, rmax, m=0.0, x0 = 0.0, y0 = 0.0;
	setlocale(LC_ALL, "Rus");
	printf("Начните вводить координаты пяти точек\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%lf\n", &A[i]); 
	}
	for (i = 0; i < 10; i=i+2)
	{
		rmax = sqrt((A[i] - x0)*(A[i] - x0) + (A[i + 1] - y0)*(A[i + 1] - y0));
		if (rmax > m)
			m = rmax - EPS;
	}
	printf("Максимальный радиус=%lf\n", m);
	for (i = 0; i < 10; i=i+2)
	{
		rmin = sqrt((A[i] - x0)*(A[i] - x0) + (A[i + 1] - y0)*(A[i + 1] - y0));
		if (rmin < m)
			m = rmin - EPS;
	}
	printf("Минимальный радиус=%lf\n", m);
	main();
}
