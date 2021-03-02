#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void name()
{
	char *path = (char*) malloc(256);
	int l, i, s1, s2, s, j;
	printf(
			"Enter path to the file in the format: 'Drive://Path/filename.extension'. You can use both slash and backslash.\n");

	fgets(path, 256, stdin);
	l = strlen(path) - 1;
	i = l;
	while (i >= 0 && path[i] != '.')
		i--;
	s1 = l;
	s2 = l;
	while (s1 >= 0 && path[s1] != '/')
		s1--;
	while (s2 >= 0 && path[s2] != '\\')
		s2--;
	s = (s1 > s2) ? s1 : s2;
	j = s;
	j++;
	if (s < i)
	{
		if (i - s == 1)  // "Path/path/.extension"
		{
			printf("You don't input filename! Enter path again!\n");
			name();
		}
		else
		{
			for (; j < i; j++)
				printf("%c", path[j]);
		}
	}
	else if (s > i)
	{
		if (j > l)  // "Path/path/"
		{
			printf("You don't input filename! Enter path again!\n");
			name();
		}
		else
			for (; j <= l; j++)
				printf("%c", path[j]);

	}
	else
		printf("%s", path);

	free(path);

}

int main()
{
	name();
	return 0;
}

