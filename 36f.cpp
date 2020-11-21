#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int maximum(int pointmaxx, int pointmaxy2, int pointmaxy, int pointmaxx2, float X[5], float[5], float maxx, float maxy )
{
	float x[5], y[5];
	int i;
	for (i = 1; i < 5; i++)
	{
		x[i] = X[i];
		y[i] = Y[i];
	}
	for (i = 1; i < 5; i++)
	{
		if (X[i] >= maxx)
		{
			if (X[i] == maxx)
			{
				if (Y[i] > Y[pointmaxx])
				{
					pointmaxy2 = i;
					pointmaxx = i;
				}
			}
			else
			{
				maxx = X[i];
				pointmaxx = i;
			}
		}
		if (Y[i] >= maxy)
		{
			if (Y[i] == maxy)
			{
				if (X[i] > X[pointmaxy])
				{
					pointmaxx2 = i;
					pointmaxy = i;
				}
			}
			else
			{
				maxy = Y[i];
				pointmaxy = i;
			}
		}
	}
		return pointmaxx, pointmaxy2, pointmaxy, pointmaxx2;
}
int main()
{
	float X[5], Y[5];
	float x, y, r, maxx, maxy;
	int pointnumber_max, pointmaxx, pointmaxy, pointmaxy2, pointmaxx2, i;
	/*pointmaxx = 0;
	pointmaxy = 0;
	pointmaxx2 = -1;
	pointmaxy2 = -1;*/
	printf("Enter the coordinates of the point x and y\n");
	for (i = 0; i < 5; i++) {
		scanf_s("%f ", &X[i]);
		scanf_s("%f ", &Y[i]);
		maxx = X[0];
		maxy = Y[0];
		pointmaxx = maximum(0, -1, 0, -1, X, Y, maxx, maxy);
		pointmaxy2 = maximum(0, -1, 0, -1, X, Y, maxx, maxy);
		pointmaxy = maximum(0, -1, 0, -1, X, Y, maxx, maxy);
		pointmaxx2 = maximum(0, -1, 0, -1, X, Y, maxx, maxy);
	}
	printf("\n");
	if (X[pointmaxx] > Y[pointmaxy])
	{
		pointnumber_max = pointmaxx;
	}
	else { pointnumber_max = pointmaxy; }
	if (X[pointmaxx] > Y[pointmaxy] && pointmaxy2 > -1)
	{
		pointnumber_max = pointmaxy2;
	}
	else
	{
		if (pointmaxx2 > -1)
			pointnumber_max = pointmaxx2;
	}
	r = sqrt(X[pointnumber_max] * X[pointnumber_max] + Y[pointnumber_max] * Y[pointnumber_max]);
	printf("r = %f\n", r);
	printf("x = %f y = %f \n", X[pointnumber_max], Y[pointnumber_max]);
	system("pause");
	return 0;
}