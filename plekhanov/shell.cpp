#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void shellsort(int n, int arr[])
{
    int novelem, local;
    for (int i = 1; i < n; i++)
    {
        novelem = arr[i];
        local = i - 1;
        while (local >= 0 && arr[local] > novelem)
        {
            arr[local + 1] = arr[local];
            local = local - 1;
        }
        arr[local + 1] = novelem;
    }
}

int main()
{
    int N;
    printf("enter N: ");
    scanf_s("%d ", &N);
    int* arr;
    arr = (int*)malloc(N * sizeof(int));
    printf("enter massive - \n");
    for (int i = 0; i < N; i++)
        scanf_s("%d ", &arr[i]);
    shellsort(N, arr);
    printf("sort massive - \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}