#include <stdio.h>
#include <string.h>

void stroka(char* s, int len)
{
    int i, id, max, count;
    max = 0;
    id = 0;
    count = 0;
    for (i = 0; i < len; i++)
        if (s[i] != ' ') count += 1;
        else 
        {
            if (count > max) 
            {
                max = count;
                id = i - count;
            }
            count = 0;
        }

    if (count > max) 
    {
        max = count;
        id = i - count;
    }
    max += id;
    for (i = id; i < max; i++)
        putchar(s[i]);
    printf("\n");
}

main() 
{
    char s[100];
    int i, id, max, count, len;
    gets(s);
    len = strlen(s);

    stroka(s, len);
}
