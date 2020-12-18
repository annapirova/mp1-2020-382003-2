#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool pal(char *str)
{
	bool f = 1;
	int l, i;
	l = strlen(str) - 1;
	i = 0;
	while (i < l / 2 && f)
	{
		if (str[i] != str[l - 1 - i])
			f = 0;
		i++;
	}
	return f;
}
int main()
{
	char *str;
	str = (char*) malloc(256);
	puts("Input string (less than 256 character)");
	fgets(str, 256, stdin);
	str[strlen(str) - 1] = ' ';
	printf("%sis palindrom: %d", str, pal(str));
	free(str);
	return 0;
}

