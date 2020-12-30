
#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "math.h"
#define EPS 1e-9

typedef double(*function1)(double);
typedef double(*function2)(double, int);

int fact(int n)
{
	int i, t = 1;
	for (i = 1; i <= n; i++)
		t = t * i;
	return t;
}

double Ch1(double x)
{
	return 1;
}

double Ch2(double x, int i)
{
	return x * x / fact(2 * i);
}

double ln1(double x)
{
	return x;
}

double ln2(double x, int i)
{
	return((-1) * x * (i - 1) / (i));
}

double cos1(double x)
{
	return 1;
}

double cos2(double x, int i)
{
	return ((pow(-1, i) * pow(x, 2 * i)) / fact(2 * i));
}

double func(function1 fun1, function2 fun2, double x, int n, double rf, double* diff, int* k, double eps)
{
	double f1, f2, sum;
	*k = 1;
	f1 = fun1(x);
	sum = f1;
	*diff = fabs(sum - rf);
	while ((*k < n) && (*diff > EPS))
	{
		f2 = f1 * fun2(x, *k);
		sum += f2;
		f1 = f2;
		(*k)++;
		*diff = fabs(sum - rf);
	}
	return sum;
}

//void print(double* x, double* n, double* eps)
//{
//	printf("Enter X\n");
//	scanf_s("%lf", x);
//	printf("Enter N \n");
//	scanf_s("%d", n);
//	printf("Enter EPS\n");
//	scanf_s("%lf", eps);
//}
void menu()
{
	printf("MENU\n");
	printf("1.cos(x)\n");
	printf("2.ch(x)\n");
	printf("3.ln(1+x)\n");
}

void main()
{
	double rf; 
	double f; 
	double x;
	int k; 
	double diff; 
	int n;
	int t = 4;
	
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		k = 0;
		switch (t)
		{
		case 1:
		{
			printf("cos(x)\n");
			scanf_s("%lf", &x);
			scanf_s("%d", &n);
			//print(&x, &n, &eps);
			rf = cos(x);
			f = func(cos1, cos2, x, n, rf, &diff, &k, EPS);
			printf("Ideal: %.5f\n", rf);
			printf("value: %.5f\n", f);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", k);
			break;
		}
		case 2:
		{
			printf("ch(x)\n");
			scanf_s("%lf", &x);
			scanf_s("%d", &n);
			//print(&x, &n, &eps);
			rf = cosh(x);
			f = func(Ch1, Ch2, x, n, rf, &diff, &k, EPS);
			printf("Ideal: %.5f\n", rf);
			printf("value: %.5f\n", f);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", k);
			break;
		}
		case 3:
		{
			printf("ln(1+x)\n");
			scanf_s("%lf", &x);
			scanf_s("%d", &n);
			//print(&x, &n, &eps);
			rf = log(1 + x);
			f = func(ln1, ln2, x, n, rf, &diff, &k, EPS);
			printf("Ideal: %.5f\n", rf);
			printf("value: %.5f\n", f);
			printf("Difference: %.5f\n", diff);
			printf("Number of terms: %d\n", k);
			break;

		}
		case 0:
		{
			break;
		}
		break;
		}
	}
}