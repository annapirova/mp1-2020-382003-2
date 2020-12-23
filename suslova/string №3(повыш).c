#include "stdio.h"
#include "string.h"

void main()
{
	char* str = "C:\\Users/User\\OneDrive\\Рабочий стол/exam_part_1.pdf";
	int len, slash, tochka;
	len = strlen(str);
	slash = len;
	tochka = len;

	while ((str[slash] != '/') && (str[slash] != '\\'))
	{
		slash--;
	}
	while (str[tochka] != '.')
	{
		tochka--;
	}
	for (len = slash; len < tochka; len++)
		printf("%c", str[len]);
}
