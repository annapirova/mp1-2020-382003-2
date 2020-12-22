#include<stdio.h>
#include<locale.h>
#include <string.h>

void name(char* str, int len)
{
    int in, ik, i;
    for (i = 0; i < len; i++)
        if ((str[i] == '/') || (str[i]) == '\\')
            in = i + 1;
    
    for (i = in; i < len; i++)
        if (str[i] == '.')
            ik = i - 1;

    for (i = in; i <= ik; i++)
        printf("%c", str[i]);
}

void main()
{
    char str[125];
    int len;
    gets(str);
    len = strlen(str);
    name(str, len);
}