#include "locale.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcAC(double x, double eps,int *i)
{
	 int k = 1;
	double x0 = x, x1, t, t1, s = x;
	t = 1.0*(k) / (k + 1);
	t1 = x*x*x;
	x1 = t1*t / (k + 2);
	while (fabs(x1 - x0) >= eps)
	{
		s += x1;
		(k)+= 2;
		t *= 1.0*(k)/ (k + 1);
		t1 *= x*x;
		x0 = x1;
		x1 = t1*t / (k + 2);
	}
	(*i) = k;
	return 0.5*3.1415926535 - s;
}

double funcLN(double x, double eps, int *i) {

	double lastresult, result;
	int n = 0;
	lastresult = 0;

	do {
		result = lastresult;
		lastresult += (pow(-1, n) * pow(x, n + 1)) / (n + 1);
		n++;
	} while (fabs(lastresult - result) >= eps);
	(*i) = n;
	return lastresult;
}
double StartPer(double *x1,double *x2,double *dx,double *eps){
	double t1,t2,t3,t4;
	printf("\nВведите начальное значение -1<Х<1 :");
	scanf_s("%lf", x1);
	printf("\nВведите конечное значение -1<Х<1 :");
	scanf_s("%lf", x2);
	printf("\nВведите шаг для формулы :");
	scanf_s("%lf", dx);
	printf("\nВведите точность для формулы :");
	scanf_s("%lf",eps);
}
double ObnullPer(double *rr,double *x1, double *x2, double *dx, double *eps, double *itr) {
	(*rr) = 0;
	(*x1) = 0;
	(*x2) = 0;
	(*dx) = 0;
	(*eps) = 0;
	(*itr) = 0;
}
void menu()
{
	printf("\nМЕНЮ_Выбор функций_Тейлор:\n");
	printf("#1. Ln(1+x) \n");
	printf("#2. Arccos(x) \n");
	printf("#3. Sin(x)\n");
	printf("0. Выход\n");
	printf("_________________________________________________\n");
	printf("Поле ввода>>");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("Программа по разложению функции через ряд Тейлора\n");
	printf("_____________________________________________");
	int t = 4;
	
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{	
			double x;   /* аргумент функции */
			double rr = 0;      /* результат вычисления функции */
			double x1;     /* начало интервала */
			double x2;      /* конец интервала */
			double dx;    /* шаг */
			double eps; /* точность */
			int iter = 0;       /* итерации -- количество слогаемых */
			printf("\nТейлор Ln(1+x)");
			StartPer(&x1, &x2, &dx, &eps);
			printf("| Аргумент X |        ln(x + 1)/  t   | Кол-во членов |        ln(x + 1)        |\n");

			/* циклом проходим по всему заданному диапазону */
			while (x1 <= x2)
			{
				rr = funcLN(x1, eps, &iter);
				printf("|   %5.2f    |    %16.13f    |     %5d     |     %16.13f    |\n", x1, rr, iter, log(x1 + 1));
				x1 += dx;
			}
			x1 -= dx;
			printf("\nВсего переменных для достижения нужной точности: %5d", iter);
			printf("\nРазница между оценкой и эталонным значением: %16.30f", (log(x1+1) - rr));
			ObnullPer(&rr,&x1, &x2, &dx, &eps,&iter);
			break;
		}
		case 2:
		{
			printf("Тейлор Arccos x");
			double x;   /* аргумент функции */
			double rr = 0;      /* результат вычисления функции */
			double x1;     /* начало интервала */
			double x2;      /* конец интервала */
			double dx;    /* шаг */
			double eps; /* точность */
			int iter = 1;       /* итерации -- количество слогаемых */
			StartPer(&x1, &x2, &dx, &eps);
			printf("| Аргумент X |        Acos(x)/  t   | Кол-во членов |        Acos(x)          |\n");
			while (x1 <= x2)
			{
				rr = funcAC(x1, eps, &iter);
				printf("|   %5.2f    |%16.13f|     %5d     |%16.13f|\n", x1, rr, iter, acos(x1));
				x1 += dx;
			}
			x1 -= dx;
			printf("\nВсего переменных для достижения нужной точности: %5d", iter);
			printf("\nРазница между оценкой и эталонным значением: %16.30f", (acos(x1) - rr));
			ObnullPer(&rr, &x1, &x2, &dx, &eps, &iter);
			break;
		}
		}
	}
}