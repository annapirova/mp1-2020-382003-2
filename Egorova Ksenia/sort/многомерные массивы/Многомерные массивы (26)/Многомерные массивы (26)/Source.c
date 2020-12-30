#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

void main() 
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    scanf_s("%d", &n);

    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * n);
    }

    int i, j, k;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            scanf_s("%d", &arr[i][j]);
        }
    }

    int flag = 1;
    int* count_line = (int*)malloc(sizeof(int) * n);
    int* count_column = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) 
    {
        count_line[i] = 0;
        count_column[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] >= 1 && arr[i][j] <= n && arr[j][i] >= 1 && arr[j][i] <= n)
            {
                count_line[arr[i][j] - 1]++;
                count_column[arr[j][i] - 1]++;
            }
        }
        for (k = 0; k < n; k++)
        {
            if (count_line[k] != 1)
            {
                flag = 0;
                break;
            }
            if (count_column[k] != 1)
            {
                flag = 0;
                break;
            }
        }
        for (k = 0; k < n; k++)
        {
            count_line[k] = 0;
            count_column[k] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    free(count_line);
    free(count_column);

    if (flag) 
    {
        printf("ћатрица €вл€етс€ латинским квадратом!");
    }
    else
    {
        printf("ћатрица не €вл€етс€ латинским квадратом!");
    }
    return 0;
}
