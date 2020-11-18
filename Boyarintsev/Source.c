/* Number 9
#include "stdio.h"
#include "math.h"
void main()
{
	double r, q, p;
	int d;
		printf("Enter r circle\n");
	scanf_s("%lf", &r);
		printf("Enter diagonal q and p\n");
	scanf_s("%lf", &q);
	scanf_s("%lf", &p);
	d = 2 * r;
	if ((q>d)&&(p>d))
	{
		printf("Right!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
}
*/
/* Number 5
#include "stdio.h"
#include "math.h"
void main()
{
	double a, b, c, x1, x2, x3, d;
	printf("Enter a,b\n");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	x1 = -b / a;
	printf("x = %3.3f\n", x1);
	printf("Enter c\n");
	scanf_s("%lf", &c);
	d = (b * b) - 4 * a * c;
	if (d>0)
	{
		printf("Has 2 solutions\n");
		x2 = ((-b) + sqrt(d)) / (2 * a);
		x3 = ((-b) - sqrt(d)) / (2 * a);
		printf("x1 = %3.3f\n", x2);
		printf("x2 = %3.3f\n", x3);
	}
	else
	{
		if (d==0)
		{
			printf("Has 1 solution");
			x2 = ((-b) + sqrt(d)) / (2 * a);
			x3 = ((-b) - sqrt(d)) / (2 * a);
			printf("x1 = x2 = %3.3f\n", x2);
		}
		else
		{
			if (d < 0)
			{
				printf("Hasn't solutions\n");
			}
		}
		
	}
}
*/


/*#include "stdio.h"
#include "math.h"
void main()
{
	double x ;
	int j, i;
	int c = 0;
	printf("Enter n\n");
	scanf_s("%lf", &x);
	for (int i = 2; i <= x; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if ((i % j == 0) && (i != j))
			{
				c = 1;
			}
			
		}
		if (c == 0)
		{
			printf("%d\n", i);
		}
		c = 0;
		
	}
		
}
*/
/*#include "stdio.h"
#include "math.h"
#include <stdbool.h>
void main()
{
	int s = 0;
	int num;
	bool check = true;
	scanf_s("%d", &num);
	if (num < 0)
	{
		check = false;
	}
	while (true)
	{
		scanf_s("%d", &num);
		if (num == 1000)
		{
			break;
		}
		if ((num < 0) && (check == true))
		{
			s = s + 1;
			check = false;
		}
		else if ((num > 0) && (check == false))
		{
			s = s + 1;
			check = true;
		}
	}
	printf("%d", s);

}
*/
