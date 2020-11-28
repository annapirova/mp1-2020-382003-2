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
	int i, t, l = 0, r = n - 1;

    while (l < r)
    {
    	for (i = l; i < r; i++)
	    {
		    if (a[i] > a[i + 1])
        		{
	        		t = a[i];
		    	a[i] = a[i + 1];
			    a[i + 1] = t;
				
	        }
        }

        r = r - 1;

        for (i = r; i > l; i--)
	    {
		    if (a[i] < a[i - 1])
		    {
			    t = a[i];
			    a[i] = a[i - 1];
			    a[i - 1] = t;
			
    		}
	    }
	    l++;
    }
}

void sortv(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > t))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}

void menu()
{
    printf("1. создать массив \n");
    printf("2. отсортировать пузырьковой сортировкой \n");
    printf("3. отсортировать сортировкой вставками \n");
    printf("4. вывести массив \n");
    printf("0. выйти \n");
}

void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, a[100];
    srand(12223);
    while (t != 0 )
    {
    
    menu();
    scanf("%d", &t);
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