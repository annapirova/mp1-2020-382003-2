#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#define EPS 1e-9

typedef double (*FunctionF)(double);
typedef double (*FunctionN)(double);

double Factor(int n)
{
	int i;
	double m;
	m = 1;
	for (i = 0; i < n; i++)
	{
		m *= i;
		return m;
	}
}

double BinCoef(int n, int k)
{
	return Factor(n) / (Factor(k) * Factor(n - k));
}

double Bern(int n)
{
	double b, sum;
	int k;
	sum = 0;
	if (n > 0)
	{
		for (k = 0; k <= n; k++)
			sum += BinCoef(n + 1, k + 1) * Bern(n - k);
		b = (-1.0 / (double)(n + 1)) * sum;
		
		return b;

	}
	else
	{
		return 1;
	}
}

double lnF(double x)
{
	return x;
}

double lnN(double x, int i)
{
	return((-1) * x * (i - 1) / (i));
}

double ChF(double x)
{
	return 1;
}

double ChN(double x, int i)
{
	return x * x / (double)(2 * i * (2 * i - 1));
}

double SinF(double x)
{
	return x;
}

double SinN(double x, int i)
{
	return (-1) * x * x / (double)(2 * i * (2 * i + 1));
}

double sum(FunctionF first, FunctionN next, double x, int kmax, double ideal, double* diff, int* i)
{
	double elem, elemN, sum;
	*i = 1;
	elem = first(x);
	sum = elem;
	*diff = fabs(sum - ideal);
	while (*i < kmax && *diff > EPS)
	{
		elemN = elem * next(x, *i);
		sum += elemN;
		elem = elemN;
		*diff = fabs(sum - ideal);
		(*i)++;
	}

	return sum;
}

int menu()
{
	printf(" 1. ln(1 + x)\n");
	printf(" 2. ch(x)\n");
	printf(" 3. sin(x)\n");
	printf(" 0. Exit\n");
}

int main()
{
	int n, i, k;
	double x, y;
	double diff;

	k = 1;
	i = 0;

	printf("Enter X: \n");
	scnaf_s("%lf", &x);

	printf("Number of terms: \n");
	scnaf_s("%d", &n);

	while (k != 0)
	{
		menu();
		scanf_s("%d", &k);

		switch (k)
		{
		case 1:
			printf(" 1. ln(1 + x) \n");
			double ideal = log(1 + x);
			double y = sum(lnF, lnN, x, n - 1, ideal, &diff, &i);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;

		case2: 
			printf(" 2. ch(x) \n");
			double ideal = cosh(x);
			double y = sum(ChF, ChN, x, n - 1, ideal, &diff, &i);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;

		case 3:
			printf(" 3. sin(x)\n");
			double ideal = sin(x);
			double y = sum(SinF, SinN, x, n - 1, ideal, &diff, &i);
			printf("Ideal: %.5f\n", ideal);
			printf("value: %.5f\n", y);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", i);
			break;
			
		default:
			printf("Please, enter number 1 to 3");
		}
	}
}
