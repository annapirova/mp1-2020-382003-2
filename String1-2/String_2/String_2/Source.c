#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main(void) {
	char* name = "C:\\Users/ermol/Documents\\1YgrEFJwCt.jpg";
	int i = strlen(name);
	int sl = i;
	int tc = i;
	while ((name[sl-1] != '/')&&(name[sl-1] != '\\'))
	{
		sl--;
	}
	while (name[tc - 1] != '.')
	{
		tc--;
	}
	
	for (int i = (sl); i < (tc-1); i++) printf("%c", name[i]);
}