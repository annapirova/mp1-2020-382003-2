#include "stdio.h"
#include "locale.h"
#include "string.h"
 
void FindWord(char str[], char maxw[])
{
	int i = 0, clet = 0, max=0, id=0, j = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
			clet++;
		else 
		{
			if (clet >= max)
			{
				max = clet;
				id = i - clet;
			}
			clet = 0;
		}
		i++;
	}
	if (clet > max)
	{
		max = clet;
		id = i - clet;
		clet = 0;
	}
	for (i = id, j = 0; i < id + max; i++, j++)
	{
		maxw[j] = str[i];
	}
	maxw[j]= '\0';
}

void main()
{
	char str[256];
	char maxw[128];
	setlocale(LC_CTYPE, "Russian");

	printf("Введите строку:\n");
	gets(str);
	FindWord(str, maxw);
	printf("Самое длинное слово:%s\n", maxw);
	return 0;
}