#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


void shell(int* B, int n)
{
    int i, j, s, prim = 1;
    while (prim > 0)
    {
        for (i = 0; i < n; i++)
        {
            j = i;
            s = B[i];
            while ((j >= prim) && (B[j - prim] > s))
            {
                B[j] = B[j - prim];
                j = j - prim;
            }
            B[j] = s;
        }
        if (prim > 1)
            prim = prim / 2;
        else if (prim == 1)
            break;
    }
}
int main()
{
    int i;
    int B[10];// = { 0, 1, 6, 3, 5, 2, 5, -1, 4, 6 };
    int n = 10;
    printf("Massiv - ");
    for (i = 0; i < n; i++)
        scanf_s("%d", &B[i]);
    shell(B, 10);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", B[i]);
    }
    return 0;
}