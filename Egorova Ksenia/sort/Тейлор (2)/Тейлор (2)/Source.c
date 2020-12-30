#define _CRT_SECURE_NO_WARNINGS
#define EPS 1e-9
#include "stdio.h"
#include "locale.h"
#include "math.h"

typedef double (*p_first)(double);
typedef double (*p_next)(double, int);

void print_commands()
{
	printf("\n\nДоступные команды:\n");
	printf("0. Завершить программу;\n");
	printf("1. Изменить входные данные;\n");
	printf("2. sin(x);\n3. arcsin(x);\n4. ln(1+x);\n");
}

double first_sin(double x)
{
	return x;
}

double next_sin(double x, int i) 
{
	return  -1 * x * x / (2 * i * (2 * i + 1));
}

double first_asin(double x) 
{
	return x;
}

double next_asin(double x, int i) 
{
	return x * x * (2 * i * (2 * i - 1)) / ((2 * i + 1) * (i * i) * pow(4, i));
}

double first_log(double x)
{
	return x;
}

double next_log(double x, int i) 
{
	return -1 * x / (i + 1);
}

double calc_sum(double x, int kmax, double ideal, double* diff, int* i, p_first first, p_next next)
{
	double value, value_next, sum;

	*i = 1;
	value = first(x);
	sum = value;
	*diff = fabs(sum - ideal);
	while (*i < kmax && *diff > EPS)
	{
		value_next = value * next(x, *i);
		sum += value_next;
		value = value_next;
		*diff = fabs(sum - ideal);
		(*i)++;
	}
	return sum;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice, flag = 1;
	double x, y;
	double diff;
	double ideal;
	int n, i = 0;

	printf("Введите x (точку, в которой необходимо вычислить значение), n (количество слагаемых):\n");
	scanf("%lf %d", &x, &n);

	while (flag)
	{
		print_commands();
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("Завершение программы.");
			flag = 0;
			break;
		case 1:
			printf("\nВведите x (точку, в которой необходимо вычислить значение), acc (точность вычисления), n (количество слагаемых):\n");
			scanf("%lf %d", &x, &n);
			break;
		case 2:
			printf("\nsin(x)\n");
			ideal = sin(x);
			y = calc_sum(x, n - 1, ideal, &diff, &i, first_sin, next_sin);
			printf("Значение функции: %.5f\n", y);
			printf("Значение стандартной функции:  %.5f\n", ideal);
			printf("Разница:  %.5f\n", diff);
			printf("Количество слагаемых:  %d", i);
			break;
		case 3:
			printf("\narcsin(x)\n");
			ideal = asin(x);
			y = calc_sum(x, n - 1, ideal, &diff, &i, first_asin, next_asin);
			printf("Значение функции: %.5f\n", y);
			printf("Значение стандартной функции:  %.5f\n", ideal);
			printf("Разница:  %.5f\n", diff);
			printf("Количество слагаемых:  %d", i);
			break;
		case 4:
			printf("\nln(1+x)\n");
			ideal = log(x);
			y = calc_sum(--x, n - 1, ideal, &diff, &i, first_log, next_log);
			printf("Значение функции: %.5f\n", y);
			printf("Значение стандартной функции:  %.5f\n", ideal);
			printf("Разница:  %.5f\n", diff);
			printf("Количество слагаемых:  %d", i);
			break;
		}
	}
	return 0;
}
