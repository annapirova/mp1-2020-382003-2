#include "locale.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
		if (n >= (*iterat)) { printf("\nОстановка"); break; }
	} 
	while (fabs(lastresult - result) >= eps);

	if (n <= (*iterat)) (*iterat) = n;
	else (*iterat) -= n;
	return lastresult;
}

double InputOptions(double *x, int *iter, double *eps) {
	printf("\nВведите значение аргумента ");
	scanf_s("%lf", x);
	printf("\nВведите максимальное количество слагаемых ");
	scanf_s("%d", iter);
	printf("\nВведите погрешность \n");
	scanf_s("%lf", eps);
}

double Clear(double *rr, double *x, double *eps, int *itr) 
{
	(*rr) = 0;
	(*x) = 0;
	(*eps) = 0;
	(*itr) = 0;
}

double CosX(double x, double eps, int* count)
{
	double sum = 0;
	double z = 1;
	int n = 0;
	while (fabs(z) > eps)
	{
		sum += z;
		if (n >= (*count))
			break;
		n++;
		z *= -x * x / (2.0 * n - 1.0) / (2.0 * n);
	}
	if ((n != 1) && (n <= (*count)))
		(*count) = n;
	else
		(*count) -= (n);
	if (n == 1)
		(*count) = n;

	return sum;
}

void menu()
{
	printf("\nРазложение по Тейлору:\n");
	printf("1) Ln(1+x) \n");
	printf("2) Sec(x)\n");
	printf("0) Выход\n");
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Программа по разложению функции через ряд Тейлора\n");
	int t = 10;
	double x;   /* аргумент функции */
	double result = 0;      /* результат вычисления функции */
	double eps; /* точность */
	int iter;   /* итерации -- количество слогаемых */

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			printf("\nТейлор Ln(1+x)");
			printf("\nЗначения -1<X<=1:");
			InputOptions(&x, &iter, &eps);
			result = LogN(x, eps, &iter);
			printf("Мой результат = %16.13f \nКол-во членов = %5d\nln(x + 1) = %16.13f\n", result, iter, log(x + 1));
			printf("\nРазница между оценкой и эталонным значением: %16.30f", (log(x + 1) - result));
			Clear(&result, &x, &eps, &iter);
			break;
		}
		case 2:
		{
			printf("Тейлор Sec x");
			InputOptions(&x, &iter, &eps);

			result = CosX(x, eps, &iter);
			printf("Мой результат = %16.13f \nКол-во членов = %5d\nSec(x) = %16.13f\n", 1/result, iter, 1/cos(x));
			printf("\nРазница между оценкой и эталонным значением: %16.30f", 1/result - 1/cos(x));
			Clear(&result, &x, &eps, &iter);
			break; 
		}
		}
	}
}