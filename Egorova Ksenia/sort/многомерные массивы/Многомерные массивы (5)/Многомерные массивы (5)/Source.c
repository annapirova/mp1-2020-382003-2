#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

void main( )
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    scanf_s("%d", &n);

    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &arr[i][j]);
        }
    }

    int res = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i][j] == arr[j][i])
            {
                res += 1;
            }
            else
            {
                res = 0;
                break;
            }
        }
        if (res == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    if (res = n - 1) 
    {
        printf("Является симметричной");
    }
    else {
        printf("Не является симметричной");
    }
    return 0;
}
