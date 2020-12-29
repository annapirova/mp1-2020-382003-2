#include "stdio.h"
#include "locale.h"

void main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int res = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i][j] == arr[j][i]) {
                res += 1;
            } 
            else {
                res = 0;
                break;
            }
        }
        if (res == 0) 
        {
            break;
        }
    }

    if (res >= n-1) 
    {
        printf("Является симметричной");
    }
    else 
    {
        printf("Не является симметричной");
    }
    return 0;
}
