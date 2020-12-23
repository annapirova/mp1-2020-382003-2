#include<stdio.h>
#include<locale.h>
#include <string.h>

char dl(char* str, int len)
{
    int i, max = 0, im = 0, count = 0;
    for (i = 0; i < len; i++)
    {
        if ((str[i] != ' ') && (str[i] != '.') && (str[i] != ',') && (str[i] != '!') && (str[i] != '?'))
            count += 1;
        else 
        {
            if (count > max) 
            {
                max = count;
                im = i - count;
            }
            count = 0;
        }
    }

    if (count > max) 
    {
        max = count;
        im = i - count;
    }
    max += im;
    for (i = im; i < max; i++)
        printf("%c", str[i]);
    printf("\n");
}

void main()
{
    char str[128];
    int len;
    gets(str);
    len = strlen(str);
    dl(str, len);

}