#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define EPS 1e-9
typedef double (*fFunction)(double);
typedef double (*nFunction)(double, int);

double fact(int n)
{
	int i;
	double m;
	m = 1;
	for (i = 1; i <= n; i++)
		m *= i;
	return m;
}

double binomCoef(int n, int k)
{
	return fact(n) / (fact(k) * fact(n - k));
}

double ber(int n)
{
	double b, sum;
	int k;
	sum = 0;
	if (n > 0)
	{
		for (k = 1; k <= n; k++)
			sum += binomCoef(n + 1, k + 1) * ber(n - k);
		b = (-1.0 / (double)(n + 1)) * sum;

		return b;
	}
	else
		return 1;
}

double fSin(double x)
{
	return x;
}

double nSin(double x, int i)
{
	return (-1) * x * x / (double) (2 * i * (2 * i + 1));
}

double fSinh(double x)
{
	return x;
}

double nSinh(double x, int i)
{
	return x * x / (double) (2 * i * (2 * i + 1));
}

double fCosh(double x)
{
	return 1;
}

double nCosh(double x, int i)
{
	return x * x / (double) (2 * i * (2 * i - 1));
}

double fTanh(double x)
{
	return x;
}

double nTanh(double x, int i)
{
	i=2*i+1;
	return /*(pow(2, 2 * i + 1) * pow(x, 2) - 2 * pow(x, 2) * ber(2 * i))
			/ (ber(2 * i - 2) * pow(2, 2 * i - 1) * pow(i, 2) - 2 * pow(i, 2)
					- i * pow(4, i - 1) + i);*/
	

	(4 * (pow(4, i) - 1) * pow(x, 2) * ber(2*i)) / (ber(2*(i-1)) * pow(4, i-1) - 1);     /*(-1)*exp(2) *x + (-1 - 2 *exp(2) *x - exp(4) *pow(x,2)) / (-3 - exp(2) *x + 2 *pow(-1,i)*exp(2 *i)*pow(x,i));/*(-1 + exp(2) * (1 - 2*exp(2*i) * pow((-x), i))*x) / (-3 + 2 * exp(2*i)* pow((-x), i) - exp(2) *x); /*(-1)*(2 * exp(2 * i + 2) * x * pow((-x), i) - exp(2) * x + 1) / (2 * pow((-x), i) * exp(2 * i) - 3 - exp(2)*x);*/
}

double sum(fFunction first, nFunction next, double x, int kmax, double ideal,
		double eps, double *diff, int *i)
{
	double elem, elemNext, sum;

	*i = 1;
	elem = first(x);
	sum = elem;
	*diff = fabs(sum - ideal);
	while (*i < kmax && *diff > eps)
	{
		elemNext = elem * next(x, *i);
		sum += elemNext;
		elem = elemNext;
		*diff = fabs(sum - ideal);
		(*i)++;
	}

	return sum;
}

double iSin(double x)
{
	return sin(x);
}
double iSinh(double x)
{
	return sinh(x);
}
double iCosh(double x)
{
	return cosh(x);
}
double iTanh(double x)
{
	return tanh(x);
}

int main()
{
	
	fFunction ff[] =
	{ fSin, fSinh, fCosh, fTanh };
	nFunction nf[] =
	{ nSin, nSinh, nCosh, nTanh };
	fFunction ideal[] =
	{ iSin, iSinh, iCosh, iTanh };
	int n, i, t;
	double x, ans, d;

	d = 0;
	i = 0;
	printf("Input x: ");
	scanf("%lf", &x);
	printf("\nChoose function sin-(1), sinh-(2), cosh-(3), tanh-(4): ");
	scanf("%d", &n);
	if (n >= 1 && n <= 3)
	{
		ans = sum(ff[n-1], nf[n-1], x, 1000, ideal[n-1](x), EPS, &d, &i);
		printf("\nans: %.15lf  ideal: %.15lf  dif: %.15lf  i: %d", ans, ideal[n-1](x), d, i);
	}
	else if (n == 4)
	{
		ans = sum(ff[1], nf[1], x, 1000, ideal[1](x), EPS, &d, &i);
		size_t kTan = i;
		ans = ans / sum(ff[2], nf[2], x, 1000, ideal[2](x), EPS, &d, &i);
		i += kTan;
		d = fabs(ideal[3](x) - ans);
		printf("\nans: %.15lf  ideal: %.15lf  dif: %.15lf  i: %d", ans, ideal[3](x), d, i);
	}

	return 0;
}

