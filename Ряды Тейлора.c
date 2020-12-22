#include "stdio.h"
#include "math.h"
#include "locale.h"
#define _USE_MATH_DEFINES

double factorial(double n1)
{
	if (n1 == 0 || n1 == 1) return 1;
	return n1 * factorial(n1 - 1);
}

double tey_s(double x, double i)
{
	double s;
	s = pow(x, (2 * i)+1) / factorial((2 * i) + 1);
	return s;
}

double tey(double x, double i)
{
	double s;
	s = pow(x, 2 * i) / factorial(2 * i);
	return s;
}

double my_ch(double x, double a, int n, int *p)
{
	{
		int i = 0;
		double sum = 0;
		double t = a + 1;
		do
		{
			t = tey(x, i);
			sum += t;
			i++;
		} while ((i < n) && (t > a));
		*p = i;
		return sum;
	}
}

double my_sh(double x, double a, int n)
{
	double sum=0, t = a + 1;
	int i = 0;
	do
	{
		t = tey_s(x, i);
		sum += t;
		i++;
	} while ((i < n) && (t > a));
	return sum;
}

double my_cth(double x, double a, int n, int* p)
{
	return my_ch(x, a, n, p) / my_sh(x, a, n);
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
			m_ch = my_ch(x, a, n, &p);
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
			m_cth = my_cth(x, a, n, &p);
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