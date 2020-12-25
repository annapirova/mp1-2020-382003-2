#include "stdio.h"
#include "string.h"

void main()
{
	char symbol = 0;
	char str1[100];
	char str2[200];
	int len2 = 0;
	int len;
	int i = 0;

	gets(str1);
	len = strlen(str1);
	scanf_s("%c", &symbol);

	for (int i = 0; i < len; i++) 
	{
		if (str1[i] == symbol) 
		{
			str2[len2] = symbol;
			len2++;
		}
		str2[len2] = str1[i];
		len2++;
	}

	for (i = 0; i < len2; i++)
	{
		printf("%c", str2[i]);
	}
}