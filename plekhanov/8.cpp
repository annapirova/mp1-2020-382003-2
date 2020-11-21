#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
int main()
{
	char value[7];
	double kursdollar, kurseuro, kursfunt, rub;
	double sum;
	rub = 0;
	kursdollar = 65.92;
	kurseuro = 74.24;
	kursfunt = 101.18;
	printf("Enter the value: dollar, euro or funt\n");
	gets_s(value);
	printf("Enter your sum\n");
	scanf_s("%lf ", &sum);
	if (sum > 500)
	{
		sum = sum + (sum - 500) * 1.02;
	}
	if (value == "dollar")
		rub = kursdollar * sum;
	if (value == "euro")
		rub = kurseuro * sum;
	if (value == "funt")
		rub = kursfunt * sum;
	printf("Your sum in rub = %lf \n", rub);
	system("pause");
	return 0;
}