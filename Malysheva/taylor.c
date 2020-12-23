#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "locale.h"

typedef double (*function1)(int);
typedef double (*function2)(double, int);

int fact(int n)
{
    int i, t = 1;
    for (i = 1; i <= n; i++)
        t = t * i;
    return t;
}

double sqrt1(double x)
{
    return 1;
}

double sqrt2(double x, int i)
{
    int j;
    double r;
    r = (pow(x, i) * pow(-1, i + 1)) / (pow(2, i) * fact(i));
    for (j = 1; j > i; j++)
        r *= (2 * i - 3);
    return r;
}

double cos1(double x)
{
    return 1;
}

double cos2(double x, int i)
{
    return ((pow(-1, i) * pow(x, 2 * i)) / fact(2 * i));
}

int sin1(double x)
{
    return x;
}

double sin2(double x, int i)
{
    return ((pow(-1, i) * pow(x, 2 * i + 1)) / fact(2 * i + 1));
}

double taycot(double x, double toch, int* k, double ifx, int n)
{
	double sin = sin1(x), cos = cos1(x), a=1;
    double r = fabs(cos/sin - ifx);
	while ((r > toch) && (*k < n))
	{
		cos = cos + cos2(x, *k);
        sin = sin + sin2(x, *k);
        (*k)++;
        r = fabs(cos/sin - ifx);
	}
	return cos/sin;
}

double func(function1 fun1, function2 fun2, double x, double toch, int* k, double ifx, int n)
{
    double f1, f2, sum, r;
    f1 = fun1(x);
    sum = f1;
    r = fabs(ifx - sum);
    while ((r > toch) && (*k < n))
    {
        sum = (sum + fun2(x, (*k)));
        (*k)++;
        r = fabs(ifx - sum);
    }
    return sum;
}

void menu()
{
    printf("1. sqrt(1 + x)\n");
    printf("2. ctg(x) \n");
    printf("3. cos(x) \n");
}

void main()
{
    setlocale(LC_ALL, "Rus");
    int t = 1, k, n;
    double fx, ifx, x;
    double toch, ras;
    while ((t == 1) || (t == 2) || (t == 3))
    {
        menu();
        scanf("%d", &t);
        printf("введите x \n");
        scanf("%lf", &x);
        printf("введите число элементов ряда \n");
        scanf("%d", &n);
        printf("введите точность вычислений \n");
        scanf("%lf", &toch);
        k = 1;

        switch(t)
        {
            case 1:
            {
                ifx = sqrt(1 + x);
                fx = func(sqrt1, sqrt2, x, toch, &k, ifx, n);
                printf("эталонное значение %.10f \n", ifx);
                printf("вычислительная оценка %.10f \n", fx);
                printf("разница между оценкой и эталонным значением %.10f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            case 2:
            {
                ifx = cos(x)/sin(x);
                fx = taycot(x, toch, &k, ifx, n);
                printf("эталонное значение %.10f \n", ifx);
                printf("вычислительная оценка %.10f \n", fx);
                printf("разница между оценкой и эталонным значением %.10f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            case 3:
            {
                ifx = cos(x);
                fx = func(cos1, cos2, x, toch, &k, ifx, n);
                printf("эталонное значение %.10f \n", ifx);
                printf("вычислительная оценка %.10f \n", fx);
                printf("разница между оценкой и эталонным значением %.10f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            default:
            break;
        }
    }
}