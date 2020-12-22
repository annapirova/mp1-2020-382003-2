#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "locale.h"

typedef double (*function1)(double);
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
    if (i == 1) 
        return x/2;
    else return ((-x * (2 * i - 1))/ (2 * fact(i)));
}

double cos1(x)
{
    return 1;
}

double cos2(x, i)
{
    return ((-1) * pow(x, 2) / 2 * i * (2 * i + 1));
}

double cot1(double x)
{
    return 1/x;
}

double cot2(double x, int i)
{
    if (i == 1)
        return ((-x * x) / 3);
    else return ((pow(x, 2)*(i - 1))/ 3 * (2*i-1));
}

double func(function1 fun1, function2 fun2, double x, long double toch, int* k, double ifx, int n)
{
    double f1, f2, sum;
    f1 = fun1(x);
    sum = f1;
    while((fabs(ifx - sum)) && (*k < n))
    {
        f2 = f1 * fun2(x, *k);
        sum = sum + f2;
        f1 = f2;
        (*k)++;
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
    double x, fx, ifx;
    long double toch, ras;
    while ((t == 1) || (t == 2) || (t == 3))
    {
        menu();
        scanf("%d", &t);
        printf("введите x \n");
        scanf("%f", &x);
        printf("введите число элементов ряда \n");
        scanf("%d", &n);
        printf("введите точность вычислений \n");
        scanf("%f", &toch);
        k = 1;

        switch(t)
        {
            case 1:
            {
                ifx = sqrt(1 + x);
                fx = func(sqrt1, sqrt2, x, toch, &k, ifx, n);
                printf("эталонное значение %.5f \n", ifx);
                printf("вычислительная оценка %.5f \n", fx);
                printf("разница между оценкой и эталонным значением %.5f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            case 2:
            {
                ifx = cos(x)/sin(x);
                fx = func(cot1, cot2, x, toch, &k, ifx, n);
                printf("эталонное значение %.5f \n", ifx);
                printf("вычислительная оценка %.5f \n", fx);
                printf("разница между оценкой и эталонным значением %.5f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            case 3:
            {
                ifx = cos(x);
                fx = func(cos1, cos2, x, toch, &k, ifx, n);
                printf("эталонное значение %.5f \n", ifx);
                printf("вычислительная оценка %.5f \n", fx);
                printf("разница между оценкой и эталонным значением %.5f \n", fabs(ifx - fx));
                printf("количество слагаемых %d \n", k);
                break;
            }
            default:
            break;
        }
    }
}