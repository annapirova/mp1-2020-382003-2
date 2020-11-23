#include <stdio.h>
#include "locale.h"

void carray(int a[], int n)
{ 
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
}

void printarray(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d \t", a[i]);
    }
    printf("\n");
}

void sortp(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void sortv(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        for (j = i; j > 0; j--)
            while (a[j] < a[j - 1])
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
    }
}

void menu()
{
    printf("1. создать массив \n");
    printf("2. отсортировать пузырьковой сортировкой \n");
    printf("3. отсортировать сортировкой вставками \n");
    printf("4. вывести массив \n");
}

void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, a[100];
    srand(12223);
    while ((t == 1) || (t == 2) || (t == 3) || (t == 4))
    {
    
    menu();
    scanf_s("%d", &t);
    switch(t)
    {
        case 1:
            n = 1 + rand() % 100;
            carray(a, n);
            break;
        case 2:
            sortp(a, n);
            break;
        case 3:
            sortv(a, n);
            break;
        case 4:
            printarray(a, n);
            break;
        default:
            break;
    }
    }
    
}