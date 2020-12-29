#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "math.h"

void print_commands()
{
	printf("Доступные команды:\n");
	printf("0. Завершить программу;\n");
	printf("1. Изменить входные данные;\n");
	printf("2. sin(x);\n3. arcsin(x);\n4. cth(x);\n");
}

double my_sin(double x, int n)
{
    double res = 0.0, num = x;
    for (long long i = 1; i <= n; i++)
	{
        res += num;
        num *= -1 * x * x / (2 * i * (2 * i + 1));
    }
    return res;
}

double my_asin(double x, int n)
{
    double res = 0.0, num = x;
    for (long long i = 1; i <= n; i++)
	{
        res += num;
        num *= x * x * (2 * i * (2 * i - 1)) / ((2 * i + 1) * (i * i) * pow(4, i));
    }
    return res;
}

double my_cth(double x, int n)
{
    double res1 = 0.0, num = x;
    for (long long i = 1; i <= n; i++)
	{
        res1 += num;
        num *= x * x / (2 * i * (2 * i + 1));
    }

    double res2 = 0.0;
    num = 1.0;
    for (long long i = 1; i <= n; i++)
	{
        res2 += num;
        num *= x * x / (2 * i * (2 * i - 1));
    }

    return res2 / res1;
}

void main() 
{
	setlocale(LC_CTYPE, "rus");
	int choice, flag = 1;
	double x;
	int n;

	print_commands();
	printf("\nВведите x (точку, в которой необходимо вычислить значение), n (количество слагаемых):\n");
	scanf("%lf %d", &x, &n);

	double res_func, res_my_func, error;
	while (flag)
	{
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
			printf("\nx\t\t\tsin(x)\t\t\tmy_sin(x)\t\terror(x)\n\n");
			res_func = sin(x);
			res_my_func = my_sin(x, n);
			error = res_func - res_my_func;
			printf("%lf\t\t%lf\t\t%lf\t\t%e\n\n", x, res_func, res_my_func, error);
			printf("Количество слагаемых: %d", n);
			break;
		case 3:
			printf("\nx\t\t\tarcsin(x)\t\tmy_arcsin(x)\t\terror(x)\n\n");
			res_func = asin(x);
			res_my_func = my_asin(x, n);
			error = res_func - res_my_func;
			printf("%lf\t\t%lf\t\t%lf\t\t%e\n\n", x, res_func, res_my_func, error);
			printf("Количество слагаемых: %d", n);
			break;
		case 4:
			printf("\nx\t\t\tcth(x)\t\t\tmy_cth(x)\t\terror(x)\n\n");
			res_func = 1.0 / tanh(x);
			res_my_func = my_cth(x, n);
			error = res_func - res_my_func;
			printf("%lf\t\t%lf\t\t%lf\t\t%e\n\n", x, res_func, res_my_func, error);
			printf("Количество слагаемых: %d", n);
			break;
		}
	}
	return 0;
}
