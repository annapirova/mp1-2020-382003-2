#include <locale.h>
#include <stdio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    char lowAl[] = { "àáâãäåæçèêëìíîïğñòóôõö÷øùúûüışÿ" };
    char upAl[] = { "ÀÁÂÃÄÅÆÇÈÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß" };
    char str[201];
    int up = 0, lett = 0;
    int k = 0, len = 0, qual = 32, tmp = 0;
    gets_s(str);
    len = strlen(str);
    printf("Ââåäèòå k: ");
    scanf("%d", &k);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < qual; j++)
        {
            if (str[i] == lowAl[j])
            {
                tmp = j;
                up = 0;
                lett = 1;
                break;
            }
            else if (str[i] == upAl[j])
            {
                tmp = j;
                up = 1;
                lett = 1;
                break;
            }
        }
        if (up && lett)
        {
            str[i] = upAl[(tmp + qual - k) % qual];
        }
        else if (lett)
        {
            str[i] = lowAl[(tmp + qual - k) % qual];
        }
    }
	
    for (int i = 0; i < len; ++i)
    {
        printf("%c", str[i]);
    }
    return 0;
}

