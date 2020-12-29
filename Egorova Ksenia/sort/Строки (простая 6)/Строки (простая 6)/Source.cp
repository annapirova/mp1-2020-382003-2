#include "stdio.h"
#include "string.h"

int is_digit(char symbol)
{
    switch (symbol)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
}

void main()
{
    char line[] = "4+7-2-8";
    int res = is_digit(line[0]);
    for (int i = 1; i < strlen(line); i += 2)
    {
        if (line[i] == '+') 
        {
            res += is_digit(line[i + 1]);
        }
        else 
        {
            res -= is_digit(line[i + 1]);
        }
    }
    printf("%d", res);
    return 0;
}
