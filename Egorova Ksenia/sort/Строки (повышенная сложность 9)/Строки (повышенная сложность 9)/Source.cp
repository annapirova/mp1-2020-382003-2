#include "stdio.h"
#include "string.h"
#include "locale.h"

void main()
{
    setlocale(LC_CTYPE, "rus");
    char line[] = "Программа";
    int size = strlen(line);
    char res[100];

    int i, lot = 0;
    for (i = 1; i <= size; i++)
    {
        if (i % 2 == 0)
        {
            res[lot] = line[i - 1];
            lot++;
        }
    }
    for (i = size; i > 0; i--)
    {
        if (i % 2 == 1) 
        {
            res[lot] = line[i - 1];
            lot++;
        }
    }
    res[lot] = '\0';

    printf("%s", res);
    return 0;
}
