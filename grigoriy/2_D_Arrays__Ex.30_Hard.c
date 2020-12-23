#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

void ran(int *ar, int n) {
    srand(time(NULL));
    int i;

    for (i = 0; i < n; i++)
        ar[i] = rand() % 2;
}

int *mal(int n) {
    int *array = (int *) malloc(sizeof(int) * n);
    return array;
}

void print(int *a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++)
            printf("%d ", a[i * n + j]);
    }
}

void func(const int *array, int n, int m, int k) {
    bool f;
    int i, j;
    int *sum = mal(n);

    for (i = 0; i < n; i++)
        sum[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            sum[i] += array[i * n + j];
    if (k <= m - sum[0]) {
        printf("\nVan №%d", 1);
        f = 1;
    }
    for (i = 1; i < n - 1; i++) {
        if (k <= m - sum[i]) {
            printf("\nVan №%d", i + 1);
            f = 1;
        } else if ((k - (int) (k / 2)) <= m - sum[i]) {
            if ((int) (k / 2) <= m - sum[i + 1]) {
                printf("\nVan №%d and Van №%d", i + 1, i + 2);
                f = 1;
            } else if ((int) (k / 2) <= m - sum[i - 1]) {
                printf("\nVan №%d and Van №%d", i, i + 1);
                f = 1;
            }
        }
    }
    if (k <= m - sum[n - 1]) {
        printf("\nVan №%d", i + 1);
        f = 1;
    }
    if (!f)
        printf("\nThere are no suitable vans");
    free(sum);
}

int main() {
    int *A;
    int n, m, k;
    printf("Enter N:");
    scanf("%d", &n);
    printf("\nEnter M:");
    scanf("%d", &m);
    printf("\nEnter k:");
    scanf("%d", &k);
    A = mal(n * m);
    ran(A, n * m);
    print(A, n, m);
    func(A, n, m, k);
    free(A);
    return 0;
}

