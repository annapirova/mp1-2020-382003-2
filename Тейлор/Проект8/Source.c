#include "locale.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double(*functionType) (double, int);

double LogN(double x, double eps, int *iterat) 
{
	double lastresult, result;
	int n = 0;
	lastresult = 0;
	do 
	{
		result = lastresult;
		lastresult += (pow(-1, n) * pow(x, n + 1)) / (n + 1);
		n++;
		//if (n >= (*iterat)) { printf("\n���������"); break; }
	} 
	while ((fabs(lastresult - result) >= eps)&&(n<(*iterat)));

	if (n <= (*iterat)) (*iterat) = n;
	else (*iterat) -= n;
	return lastresult;
}

/* ��������, �� ������� ������ ����������� ���������� � ���� ���������� ������� cos(x) */
double Nextcos(double x, int i)
{
	double result;
	result = pow(-1, i) * pow(x, 2 * i) / (2 * i*(2 * i - 1));
	return result;
}

/* ������������ ����������� ��������� �� �������� ��������*/
double SUM(functionType ff, double x, double a1, double e)
{
	double i = 1, elem = x, elemNext, result = x;
	while (fabs(result - a1) > e)
	{
		elemNext = elem * ff(x, i);
		result += elemNext;
		i++;
	}
	return result;
}

double InputOptions(double *x, int *iter, double *eps) {
	printf("\n������� �������� ��������� ");
	scanf_s("%lf", x);
	printf("\n������� ������������ ���������� ��������� ");
	scanf_s("%d", iter);
	printf("\n������� ����������� \n");
	scanf_s("%lf", eps);
}

double Clear(double *rr, double *x, double *eps, int *itr) 
{
	(*rr) = 0;
	(*x) = 0;
	(*eps) = 0;
	(*itr) = 0;
}

void menu()
{
	printf("\n���������� �� �������:\n");
	printf("1) Ln(1+x) \n");
	printf("2) Sec(x)\n");
	printf("0) �����\n");
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("��������� �� ���������� ������� ����� ��� �������\n");
	int t = 10;
	double x;   /* �������� ������� */
	double result = 0;      /* ��������� ���������� ������� */
	double eps; /* �������� */
	int iter;   /* �������� -- ���������� ��������� */

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			printf("\n������ Ln(1+x)");
			printf("\n�������� -1<X<=1:");
			InputOptions(&x, &iter, &eps);
			result = LogN(x, eps, &iter);
			printf("��� ��������� = %16.13f \n���-�� ������ = %5d\nln(x + 1) = %16.13f\n", result, iter, log(x + 1));
			printf("\n������� ����� ������� � ��������� ���������: %16.30f", (log(x + 1) - result));
			Clear(&result, &x, &eps, &iter);
			break;
		}
		case 2:
		{
			double t1, c1;
			printf("������ Sec x");
			printf("\n������� �������� ��������� ");
			scanf_s("%lf", &x);
			printf("\n������� ����������� \n");
			scanf_s("%d", &eps);
			t1 = pow(10.0, -1 * eps);
			c1 = cos(x);
			result = SUM(Nextcos, 1, c1, t1);
			printf("��� ��������� = %16.13f \nSec(x) = %16.13f\n", 1 / result, 1 / cos(x));
			printf("\n������� ����� ������� � ��������� ���������: %16.30f", 1/result - 1/cos(x));
			Clear(&result, &x, &eps, &iter);
			break; 
		}
		}
	}
}