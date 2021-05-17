#include "stdio.h"
void QuickSort(int* A, int n) 
{

    int i = 0;
    int j = n - 1;
    int mid = A[n / 2];
    do {
        while (A[i] < mid) 
        {
            i++;
        }
        while (A[j] > mid) 
        {
            j--;
        }
        if (i <= j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) 
    {   
        QuickSort(A, j + 1);
    }
    if (i < n) 
    {
        QuickSort(&A[i], n - i);
    }
}

void Print(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void main()
{
    int A[1000];
    int i, j, n;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &(A[i]));
    }
    Print(A, n);
    QuickSort(A, n);
    Print(A, n);

}