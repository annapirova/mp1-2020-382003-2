#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void MergeSort(int* A, int n)
{
    int mid = n / 2;
    if (n % 2 == 1)
        mid++;
    int h = 1; 
    int* c = (int*)malloc(n * sizeof(int));
    int s;
    while (h < n)
    {
        s = h;
        int i = 0;   
        int j = mid; 
        int k = 0;   
        while (s <= mid)
        {
            while ((i < s) && (j < n) && (j < (mid + s)))
            { 
                if (A[i] < A[j])
                {
                    c[k] = A[i];
                    i++; k++;
                }
                else
                {
                    c[k] = A[j];
                    j++; k++;
                }
            }
            while (i < s)
            { 
                c[k] = A[i];
                i++; k++;
            }
            while ((j < (mid + s)) && (j < n))
            {  
                c[k] = A[j];
                j++; k++;
            }
            s = s + h; 
        }
        h = h * 2;
        for (i = 0; i < n; i++)
        {
            A[i] = c[i];
        }
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

int main()
{
    int A[1000];
    int n;
    scanf_s("%d", &n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }
    Print(A, n);
    MergeSort(A, n); 
    Print(A, n);
}