#include "stdio.h"
#include "math.h"
#include "locale.h"

void main()
{
	int a, b, c;
	double m=0;
	setlocale(LC_ALL, "Russian");
	printf("Введите оценки\n");
	scanf_s("%i %i %i", &a, &b, &c);
	printf("a=%i b=%i c=%i\n", a, b, c);
	if ((a == 2) || (b == 2) || (c == 2))
	{
		printf("Двоечник\n");
		return;
	}
	else
	m = ((double)a + (double)b + (double)c) / 3.0;
	printf("m=%lf\n", m);
	if (m >= 4.5)
		printf("Отличник\n");
	else if ((m >= 3.5) && (m <= 4.5))
		printf("Хорошист\n");
		else if ((m >= 0) && (m <= 2.5))
		printf("Двоечник\n");	
}