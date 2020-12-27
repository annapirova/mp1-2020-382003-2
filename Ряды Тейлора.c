#include "stdio.h"
#include "math.h"
#include "locale.h"
#define _USE_MATH_DEFINES

typedef double (*Function)(double, int);

double sh(double x, int i)
{
	double s;
	if (i == 0)
	{
		s = x;
	}
	else
	s = (x * x) / ((2*i)*(2*i + 1));
	return s;
}

double ch(double x, int i)
{
	double s;
	if (i == 0)
	{
		s = 1;
	}
	else
	s = (x*x) / ((i*2 - 1)*(2*i));
	return s;
}

double my_h(double x, double a, int n, Function ff, int *p)
{
	{
		int i = 0;
		double elem = 1, elemNext=0, sum = 0;
		double t = a + 1;
		while ((i < n) && (t > a))
		{
			elemNext = elem * ff(x, i);
			sum += elemNext;
			t = elemNext;
			i++;
		}
		*p = i;
		return sum;
	}
}


void EnterAXN(double *x, double *a, int *n)
{
	int st;
	printf("Задайте точку x=");
	scanf_s("%lf", &*x);
	printf("\nЗадайте точность вычисления (a >= 1e-6) a=1e-");
	scanf_s("%d", &st);
	*a = pow(10.0, -st);
	printf("\nВведите количество членов последовательности\n");
	scanf_s("%d", &*n);
}

void menu()
{
	printf("\nMENU:\n");
	printf("1. Разложить гиперболический косинус\n");
	printf("2. Разложить гиперболический котангенс\n");
	printf("0. Exit\n");
}

void main()
{
	Function ff;
	double x, a, raz;
	double i_ch, i_cth;
	double m_ch, m_cth;
	setlocale(LC_ALL, "rus");
	int t = 10, n, p;
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			EnterAXN(&x, &a, &n);
			m_ch = my_h(x, a, n, ch, &p);
			i_ch = cosh(x);
			raz = fabs(m_ch - i_ch);
			printf("%lf %lf %d\n", x, a, n);
			printf("Вычисленный гиберболический косинус равен = %lf\n", m_ch);
			printf("Эталонный гиберболический косинус равен = %lf\n", i_ch);
			printf("Кол-во вычисленных слагаемых p = %d\n", p);
			printf("Разница между оценкой и эталонным значением = %lf\n", raz);
			break;
		}
		case 2:
		{
			EnterAXN(&x, &a, &n);
			m_cth = my_h(x, a, n, ch, &p)/ my_h(x, a, n, sh, &p);
			i_cth = cosh(x)/sinh(x);
			raz = fabs(m_cth - i_cth);
			printf("%lf %lf %d\n", x, a, n);
			printf("Вычисленный гиберболический котангенс равен = %lf\n", m_cth);
			printf("Эталонный гиберболический котангенс равен = %lf\n", i_cth);
			printf("Кол-во вычисленных слагаемых p = %d\n", p);
			printf("Разница между оценкой и эталонным значением = %lf\n", raz);
			break;
		}
		}
	}
	return;
}