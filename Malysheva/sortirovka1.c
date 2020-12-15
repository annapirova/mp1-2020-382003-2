#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include "time.h"

void carray(int* a, int n, int min, int max)
{ 
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = min + rand() % (max - min + 1);
    }
}

void printarray(int* a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d \t", a[i]);
    }
    printf("\n");
}

void sortp(int* a, int n, int* pere, int* sr)
{
	int i, t, l = 0, r = n - 1;

    while (l < r)
    {
    	for (i = l; i < r; i++)
	    {
            (*sr)++;
		    if (a[i] > a[i + 1])
        	{
	        	t = a[i];
		    	a[i] = a[i + 1];
			    a[i + 1] = t;
				(*pere)++;
	        }
        }

        r = r - 1;

        for (i = r; i > l; i--)
	    {
            (*sr)++;
		    if (a[i] < a[i - 1])
		    {
			    t = a[i];
			    a[i] = a[i - 1];
			    a[i - 1] = t;
                (*pere)++;
    		}
	    }
	    l++;
    }
}

void sortv(int* a, int n, int* pere, int* sr)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > t))
        {
            (*sr)++;
            a[j + 1] = a[j];
            j--;
            (*pere)++;
        }
        a[j + 1] = t;
        (*pere)++;
    }
}

void sli(int* a, int left, int mid, int right, int* pere, int* sr)
{
    int array[right - left];
    int i, i1 = 0, i2 = 0;
    while ((left + i1 < mid) && (mid + i2 < right))
    {
        if (a[left + i1] < a[mid + i2])
        {
            array[i1 + i2] = a[left + i1];
            i1++;
            (*pere)++;
        } 
        else
        {
            array[i2 + i1] = a[mid + i2];
            i2++;
            (*pere)++;
        }
        (*sr)++;
    }

    while (left + i1 < mid)
    {
        array[i1 + i2] = a[left + i1];
        i1++;
        (*pere)++;
    }

    while (i2 + mid < right)
    {
        array[i1 + i2] = a[mid + i2];
        i2++;
        (*pere)++;
    }
    
    for (i = 0; i < i1 + i2; i++)
        a[left + i] = array[i];   
}

void sorts(int* a, int l, int r, int* pere, int* sr)
{
    int m;
    if (l + 1 < r)
    {
        m = (l + r) / 2;
        sorts(a, l, m, &(*pere), &(*sr));
        sorts(a, m, r, &(*pere), &(*sr));
        sli(a, l, m, r, &(*pere), &(*sr));
    }
    (*pere)++;
}

void quicksort(int* a, int l, int r, int* sr, int* pere)
{
    int s, i, j, t;
    s = a[(r + l) / 2];
    i = l;
    j = r;
    while(i <= j)
    {
        while(a[i] < s)
        i++;
        while(a[j] > s)
        j--;
        if (i <= j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            (*pere)++;
            i++;
            j--;
        }
        (*sr)++;
    }
    if (l < j)
    quicksort(a, l, j, &(*sr), &(*pere));
    (*sr)++;
    if (i < r)
    quicksort(a, i, r, &(*sr), &(*pere));
    (*sr)++;
}

int binar(int* a, int n, int num, int* sr)
{
    int l = 0, r = n - 1, s;

    while (l <= r)
    {
        s = (l + r) / 2;
        (*sr)++;
        if (num > a[s])
            l = s + 1;
        else{
        (*sr)++;
        if (num < a[s])
            r = s - 1;
        else 
            return s;
        }
        
    }
    return -1;
}

int lin(int* a, int n, int num, int* sr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        (*sr)++;
        if (a[i] == num) return i;
    }
    return -1;
}

void menu()
{
    printf("1. случайная генерация массива \n");
    printf("2. ввести массив \n");
    printf("3. пузырьковая сортировка \n");
    printf("4. сортировка вставками \n");
    printf("5. сортировка слиянием \n");
    printf("6. быстрая сортировка \n");
    printf("7. бинарный поиск \n");
    printf("8. линейный поиск \n");
    printf("9. вывести массив \n");
    printf("0. выйти \n");
}

void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, min, max, i, sort, num, ibi, pass = 0;
    int* a = NULL;
    unsigned long int pere, sr;
    clock_t ttime;
    srand(12223);
    while (t != 0 )
    {
    
    menu();
    scanf("%d", &t);
    switch(t)
    {
        case 1:
            pass = 1;
            printf("введите длину массива \n");
            scanf("%d", &n);
            a = (int*)malloc(sizeof(int) * n);
            printf("введите нижнюю границу диапозона \n");
            scanf("%d", &min);
            printf("введите верхнюю границу диапозона \n");
            scanf("%d", &max);
            carray(a, n, min, max);
            sort = 0;
            break;
        case 2:
        pass = 1;
            printf("введите длину массива \n");
            scanf("%d", &n);
            a = (int*)malloc(sizeof(int) * n);
            printf("введите элементы \n");
            sort = 0;
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            break;
        case 3:
            if (pass == 1){
            sr = 0;
            pere = 0;
            ttime = clock();
            sortp(a, n, &pere, &sr);
            ttime = clock() - ttime;
            printf("время работы %f секунд \n", (double)ttime/ CLOCKS_PER_SEC);
            printf("число перестановок %d число сравнений %d \n", pere, sr);
            sort = 1;
            }
            else
            printf("введите массив \n");
            break;
        case 4:
            if (pass == 1){
            sr = 0;
            pere = 0;
            ttime = clock();
            sortv(a, n, &pere, &sr);
            ttime = clock() - ttime;
            printf("время работы %f секунд \n", (double)ttime/ CLOCKS_PER_SEC);
            printf("число перестановок %d число сравнений %d \n", pere, sr);
            sort = 1;
            }
            else printf("введите массив \n");
            break;
        case 5:
            if (pass == 1){
            sr = 0;
            pere = 0;
            ttime = clock();
            sorts(a, 0, n, &pere, &sr);
            ttime = clock() - ttime;
            printf("время работы %f секунд \n", (double)ttime/ CLOCKS_PER_SEC);
            printf("число перестановок %d число сравнений %d \n", pere, sr);
            sort = 1;
            }
            else printf("введите массив \n");
            break;
        case 6:
            if (pass == 1){
            sr = 0;
            pere = 0;
            ttime = clock();
            quicksort(a, 0, n - 1, &sr, &pere);
            ttime = clock() - ttime;
            printf("время работы %f секунд \n", (double)ttime/ CLOCKS_PER_SEC);
            printf("число перестановок %d число сравнений %d \n", pere, sr);
            sort = 1;
            }
            else printf("введите массив \n");
            break;
        case 7:
            if (pass == 1){
            printf("введите число \n");
            sr = 0;
            scanf("%d", &num);
            if (sort == 1)
            {
                ibi = binar(a, n, num, &sr);
                if (ibi == -1)
                    printf("число не найдено \n");
                else 
                    printf("номер элемента %d \n", ibi);
                printf("число сравнений %d \n", sr);             
            }
            else
            {
                printf("отсортируйте массив \n");
            }
            } 
            else printf("введите массив \n");
            break;
        case 8:
            if (pass == 1){
                printf("введите число \n");
                sr = 0;
                scanf("%d", &num);
                lin(a, n, num, &sr);
                printf("число сравнений %d \n", sr);  
            }
            else printf("введите массив \n");
            break;
        case 9:
            if (pass == 1)
            printarray(a, n);
            else printf("введите массив \n");
            break;
        default:
            break;
    }
    }
    free(a);
}