#include "stdio.h"
#include "string.h"
#include "locale.h"

main() 
{
	char B[200];
	int i, max_ind_l, max_ind_r, maxlen, count, length;
	gets(B);
	length = strlen(B);
	maxlen = 0;
	max_ind_l = 0;
	count = 0;
	for (i = 0; i<length; i++)
		if (B[i] != ' ') 
			count = count + 1;
		else 
		{
			if (count > maxlen) {
				maxlen = count;
				max_ind_l = i - count;
			}
			count = 0;
		}
		max_ind_r = maxlen + max_ind_l;
		for (i = max_ind_l; i<max_ind_r; i++)
			putchar(B[i]);
		scanf_s("%d", &i);
}