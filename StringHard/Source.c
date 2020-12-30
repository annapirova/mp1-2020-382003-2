#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

void check(char* s)
{
	int k, i, j, len_string, len_bef, len_aft;
	char space = ' ';
	char tmp;
	char* beforeSpace = ".,:;?!)}]";
	char* afterSpace = "([{";
	len_string = strlen(s) - 1;
	len_bef = strlen(beforeSpace);
	len_aft = strlen(afterSpace);
	char* sCopy = (char*)malloc(len_string);
	setlocale(LC_CTYPE, "Russian");

	for (i = 0; i < len_string; i++)
		sCopy[i] = s[i];

	printf("\nИсходный вариант:\n");
	for (i = 0; i < len_string; i++)
		printf("%c", s[i]);

	k = 1;
	while (k < len_string) 
	{
		for (i = k; i < len_string - 1; i++)
		{
			for (j = 0; j < len_bef; j++)
				if (sCopy[i] == beforeSpace[j] && sCopy[i - 1] == space)
				{
					tmp = sCopy[i];
					sCopy[i] = sCopy[i - 1];
					sCopy[i - 1] = tmp;
				}

			for (j = 0; j < len_aft; j++)
				if (sCopy[i] == afterSpace[j] && sCopy[i + 1] == space)
				{
					tmp = sCopy[i];
					sCopy[i] = sCopy[i + 1];
					sCopy[i + 1] = tmp;
				}
		}
		k++;
	}
	printf("\nРедактированный вариант:\n");
	for (i = 0; i < len_string; i++)
		printf("%c", sCopy[i]);
	free(sCopy);
}

int main()
{
	char* s = (char*)malloc(256);
	setlocale(LC_CTYPE, "Russian");
	printf("Введите текст: ");
	fgets(s, 256, stdin);
	check(s);
	free(s);
	return 0;
}