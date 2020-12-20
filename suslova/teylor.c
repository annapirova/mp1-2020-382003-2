#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define EPS 1e-9

typedef double (*FunctionFirst)(double);
typedef double (*FunctionNext)(double);

double Factorial(int n)
{
	int i;
	double m;
	m = 1;
	for (i = 1; i <= n; i++)
		m = m * i;
	return m;
}

double BinomCoeff(int n, int k)
{
	return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

double Bernully(int n)
{
	double b, sum;
	int k;
	sum = 0;
	if (n > 0)
	{
		for (k = 1; k <= n; k++)
			sum += BinomCoeff(n + 1, k + 1) * Bernully(n - k);
		b = (-1.0 / (double)(n + 1)) * sum;

		return b;
	}
	else
		return 1;
}

double FirstArctg(double x)
{
	return x;
}

double NextArctg(double x, int i)
{
	return ((-1) * x * (2 * i - 2) / (2 * i - 1));
}

double FirstTh(double x)
{
	return x;
}

double NextTh(double x, int i)
{
	i = 2 * i + 1;
	return (4 * (pow(4, i) - 1) * pow(x, 2) * Bernully(2 * i)) / (Bernully(2 * (i - 1)) * pow(4, i - 1) - 1);
}

double FirstSin(double x, int i)
{
	return x;
}

double NextSin(double x, int i)
{
	return ((-1) * pow(x, 2) / 2 * i * (2 * i + 1));
}

double sum(FunctionFirst first, FunctionNext next, double x, int kmax, double ideal, double* diff, int* i)
{
	double elem, elemNext, sum;

	*i = 1;
	elem = first(x);
	sum = elem;
	*diff = fabs(sum - ideal);
	while (*i < kmax && *diff > EPS)
	{
		elemNext = elem * next(x, *i);
		sum += elemNext;
		elem = elemNext;
		*diff = fabs(sum - ideal);
		(*i)++;
	}

	return sum;
}

void menu()
{
	{
		printf("\n________________________\n");
		printf("menu: teylor functions:\n");
		printf("\n1. arctg(x)\n");
		printf("\n2. th(x)\n");
		printf("\n3. sin(x)\n");
		printf("\n0. exit\n");
		printf("________________________\n");
	}
}

void main()
{
	int n, i, t, c;
	double x, y;
	double diff;

	c = 4;
	i = 0;
	
	printf("enter x: ");
	scanf_s("%lf", &x);

	printf("enter number of terms:\n");
	scanf_s("%d", &n);

	while (c != 0)
	{
		menu();
		scanf_s("%d", &c);

		switch (c)
		{
		case 1:
		{
			printf("\n1.arctg(x)\n");
			double ideal = atan(x);
			double y = sum(FirstArctg, NextArctg, x, n - 1, ideal, &i, &diff);
			printf("y: %.5f\n", y);
			printf("ideal:  %.5f\n", ideal);
			printf("difference:  %.5f\n", diff);
			printf("i:  %d", i);
			break;
		}
		case 2:
		{
			printf("\n2.th(x)\n");
			double ideal = tanh(x);
			double y = sum(FirstTh, NextTh, x, n - 1, ideal, &i, &diff);
			printf("function value: %.5f\n", y);
			printf("ideal:  %.5f\n", ideal);
			printf("difference:  %.5f\n", diff);
			printf("number of terms:  %d", i);
			break;
		}
		case 3:
		{
			printf("\n3.sin(x)\n");
			double ideal = sin(x);
			double y = sum(FirstSin, NextSin, x, n - 1, ideal, &i, &diff);
			printf("function value: %.5f\n", y);
			printf("ideal:  %.5f\n", ideal);
			printf("difference:  %.5f\n", diff);
			printf("number of terms:  %d", n);
			break;
		}
		}
	}
}