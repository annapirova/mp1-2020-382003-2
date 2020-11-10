// рекуррентная формула
#include "stdio.h"

// f(n) = f(n-1) + f(n-2)
int fib(int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	else
		return 1;

}

// b_n = b_1 * q^(n - 1) 
//     = b_n-1 * q

// b_1 = 2.0
// b_2 = 2.0 * 3.0 = 6.0
// b_3 = b_2 * q   = 6.0 * 3.0 = 18.0
// b_4 = b_3 * q = 18*3 = 54

double Geom(double b1, double q, int n)
{
	if (n == 1)
		return b1;
	else
		return Geom(b1, q, n - 1) * q;
}

void main()
{
	//printf("%d", fib(5));
	printf("%lf", Geom(2.0, 3.0, 4));
}