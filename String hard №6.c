#include "stdio.h"
#include "locale.h"
#include "string.h"

void Enigma(char str[], int k)
{
    char except[3] = " ,.";
    int count;
    for (int j = 0; j < 256; j++)
    {
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (str[j] != except[i])
            {
                count++;
            }
        }
        if (count == 3)
        {
            str[j] = str[j] + k;
        }
    }
}


void main()
{
    char str[256];
    int k = 0;
    int t = 0;
    int q = 0;
    setlocale(LC_CTYPE, "Russian");

    printf("Введите строку:\n");
    gets(str);
    while (str[q] != '\0')
        q++;
    printf("q=%d\n", q);
    while (t != 1)
    {
        printf("Введите число 0 < K < 10:\n");
        scanf_s("%d", &k);
        if (k < 0 || k>10)
        {
            printf("Неверное K\n");
        }
        else {
            t = 1;
        }
    }
    Enigma(str, k);
    str[q] = '\0';
    puts(str);
    return;
}