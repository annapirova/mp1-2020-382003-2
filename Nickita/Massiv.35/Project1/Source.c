#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, N1, N2, N3, * arr1, * arr2, * arr3;
    printf("Enter the size of the array 1: ");
    scanf_s("%d", &N1);
    arr1 = (int*)calloc(N1, sizeof(int));
    printf("Enter the elements of the array 1:\n");
    printf("arr1[0] = ");
    scanf_s("%d", &arr1[0]);
    for (i = 1; i < N1; i++) {
        printf("arr1[%d] = ", i);
        scanf_s("%d", &arr1[i]);
        if (arr1[i] < arr1[i - 1]) {
            printf("The sequence 1 decreases!");
            return 0;
        }
    }
    printf("Enter the size of the array 2: ");
    scanf_s("%d", &N2);
    arr2 = (int*)calloc(N2, sizeof(int));
    printf("Enter the elements of the array 2:\n");
    printf("arr2[0] = ");
    scanf_s("%d", &arr2[0]);
    for (i = 1; i < N2; i++) {
        printf("arr2[%d] = ", i);
        scanf_s("%d", &arr2[i]);
        if (arr2[i] < arr2[i - 1]) {
            printf("The sequence 2 decreases!");
            return 0;
        }
    }
    N3 = N1 + N2;
    arr3 = (int*)calloc(N3, sizeof(int));
    i = 0; j = 0; k = 0;
    while (k <= N3) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    printf("\nSorted array:\n");
    for (i = 0; i < N3; i++) {
        printf("arr[%d] = %d;\n", i, arr3[i]);
    }
    return 0;
}