#include <stdio.h>
#include "locale.h"

void carray(int a[], int n, int min, int max)
{ 
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = min + rand() % (max - min + 1);
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

void sli(int a[], int left, int mid, int right)
{
    int array[right - left];
    int i, i1 = 0, i2 = 0;
    while ((left + i1 < mid) && (mid + i2 < right))
    {
        if (a[left + i1] < a[mid + i2])
        {
            array[i1 + i2] = a[left + i1];
            i1++;
        }
        else
        {
            array[i2 + i1] = a[mid + i2];
            i2++;
        }
    }

    while (left + i1 < mid)
    {
        array[i1 + i2] = a[left + i1];
        i1++;
    }

    while (i2 + mid < right)
    {
        array[i1 + i2] = a[mid + i2];
        i2++;
    }
    
    for (i = 0; i < i1 + i2; i++)
        a[left + i] = array[i];   
}

void sorts(int a[], int l, int r)
{
    int m;
    if (l + 1 < r)
    {
        m = (l + r) / 2;
        sorts(a, l, m);
        sorts(a, m, r);
        sli(a, l, m, r);
    }
}

void menu()
{
    printf("1. случайная генерация массива \n");
    printf("2. ввести массив \n");
    printf("3. пузырьковая сортировка \n");
    printf("4. сортировка вставками \n");
    printf("5. сортировка слиянием \n");
    printf("6. вывести массив \n");
    printf("0. выйти \n");
}

void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, a[100], min, max, i;
    srand(12223);
    while (t != 0 )
    {
    
    menu();
    scanf("%d", &t);
    switch(t)
    {
        case 1:
            printf("введите длину массива \n");
            scanf("%d", &n);
            printf("введите нижнюю границу диапозона \n");
            scanf("%d", &min);
            printf("введите верхнюю границу диапозона \n");
            scanf("%d", &max);
            carray(a, n, min, max);
            break;
        case 2:
            printf("введите длину массива \n");
            scanf("%d", &n);
            printf("введите элементы \n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            break;
        case 3:
            sortp(a, n);
            break;
        case 4:
            sortv(a, n);
            break;
        case 5:
            sorts(a, 0, n);
            break;
        case 6:
            printarray(a, n);
            break;
        default:
            break;
    }
    }
    
}