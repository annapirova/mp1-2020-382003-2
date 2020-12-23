#include "stdio.h"  // задача 4 повышенной сложности
#include "string.h"
#include "locale.h"

main()
{
	char B[200];
	int i, slash_1, slash_2, length;
	gets(B);
	length = strlen(B);
	slash_1 = 0;
	slash_2 = 0;
	for (i = 0; i < length; i++)
	{
		if ((B[i] == '/')|| (B[i] == '\\'))
		{
			slash_1 = slash_2;
			slash_2 = i;
		}
	}
	for (i = slash_1 + 1; i < slash_2; i++)
		putchar(B[i]);
	scanf_s("%d", &i);
}