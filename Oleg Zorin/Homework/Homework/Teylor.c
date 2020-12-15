#define _USE_MATH_DEFINES
#define EXP 1e-15
#include "stdio.h"
#include "math.h"

typedef double (*Function)(double, double);

double step_arctg(double x, double k)
{
	return (pow(-1, k - 1) * pow(x, 2*k - 1) / (2*k - 1));
}

double Teylor(double x, double n, double accuracy, double ideal, Function step, int *kolvo)
{
	int i = 1;
	double result = 0;
	double difference = 1;

	while ((i < n) && (difference > accuracy))
	{
		result += step(x, i);
		difference = fabs(result - ideal);
		i++;
	}
	*kolvo = i;
	return result;
}

void main()
{
	Function my_arctg = step_arctg;
	double x, n, accuracy;
	int m, t;
	double res_arctg, ideal_arctg;
	double res_arcctg, ideal_arcctg;
	int k1, k2;
	
	printf("MENU:\n 1. Arctg\n 2. Arcctg\n 0. Exit\n");
	do
	{
		printf(">>> ");
		scanf_s("%d", &t);
		switch (t)
		{
		case 1: {
			do
			{
				printf("Enter value(from -1 to 1): ");
				scanf_s("%lf", &x);
			} while (((x - 1.0) > EXP) || ((x + 1.0) < EXP));
			printf("Enter the required precision: ");
			scanf_s("%d", &m);
			accuracy = pow(10.0, -m);
			printf("Enter the number of elements of the taylor series: ");
			scanf_s("%lf", &n);
			ideal_arctg = atan(x);
			res_arctg = Teylor(x, n, accuracy, ideal_arctg, my_arctg, &k1);
			printf("\nRESULTS:\nArctg(%.2lf) = %.15lf\nIdeal = %.15lf\nDifference = %.15lf\nNumber of terms = %d\n", 
				x, res_arctg, ideal_arctg, fabs(ideal_arctg - res_arctg), k1);
			break;
		}
		case 2: {
			do
			{
				printf("Enter value(from -1 to 1): ");
				scanf_s("%lf", &x);
			} while (((x - 1.0) > EXP) || ((x + 1.0) < EXP));
			printf("Enter the required precision: ");
			scanf_s("%d", &m);
			accuracy = pow(10.0, -m);
			printf("Enter the number of elements of the taylor series: ");
			scanf_s("%lf", &n);
			ideal_arcctg = M_PI_2 - atan(x);
			res_arcctg = M_PI_2 - Teylor(x, n, accuracy, atan(x), my_arctg, &k2);
			printf("\nRESULTS:\nArcctg(%.2lf) = %.15lf\nIdeal = %.15lf\nDifference = %.15lf\nNumber of terms = %d\n",
				x, res_arcctg, ideal_arcctg, fabs(ideal_arcctg - res_arcctg), k2);
			break;
		}
		case 0:
			break;
		default: {
			printf("Please, enter 1 or 2!!!\n");
			break;
		}
		}
	} while (t != 0);
	

}