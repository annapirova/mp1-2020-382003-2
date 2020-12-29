#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#include "locale.h"

void vvod_array(int a[], int n)
{
	int i;
	srand(time);

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}

void print_array(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
}

void sheikere_sort(int a[], int n, int* nc, int* nsw)
{
	int i, tmp;
	int left, right;
	left = 0;
	right = n - 1;

	*nc = *nc + 1;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			*nc = *nc + 1;
			if (a[i] > a[i + 1])
			{
				tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
				*nsw = *nsw + 1;
			}
		}
		right--;
		for (i = right; i > left; i--)
		{
			*nc = *nc + 1;
			if (a[i] < a[i - 1])
			{
				tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				*nsw = *nsw + 1;
			}
		}
		left++;
	}
}

void  Insertion_sort(int a[], int n, int* nc, int* nsw)
{
	int k, l;

	for (int i = 1; i < n; i++)
	{
		k = a[i];
		l = i - 1;

		*nc = *nc + 1;
		while (l >= 0 && a[l] > k)
		{
			a[l + 1] = a[l];
			l = l - 1;
			*nsw = *nsw + 1;
		}
		a[l + 1] = k;
	}
}

void merging(int a[], int left, int mid, int right, int* nc, int* nsw)
{
    int array[10];
    int i, l1 = 0, l2 = 0;

	*nc = *nc + 1;
    while ((left + l1 < mid) && (mid + l2 < right))
    {
		*nc = *nc + 1;
        if (a[left + l1] < a[mid + l2])
        {
            array[l1 + l2] = a[left + l1];
            l1++;
			*nsw = *nsw + 1;
        }
        else
        {
            array[l2 + l1] = a[mid + l2];
            l2++;
			*nsw = *nsw + 1;
        }
    }

	*nc = *nc + 1;
    while (left + l1 < mid)
    {
        array[l1 + l2] = a[left + l1];
        l1++;
		*nsw = *nsw + 1;
    }

	*nc = *nc + 1;
    while (l2 + mid < right)
    {
        array[l1 + l2] = a[mid + l2];
        l2++;
		*nsw = *nsw + 1;
    }

	for (i = 0; i < l1 + l2; i++)
	{
		a[left + i] = array[i];
		*nsw = *nsw + 1;
	}
}

void merging_sort(int a[], int n, int left, int right, int *nc, int *nsw)
{
    int mid;

	*nc = *nc + 1;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        merging_sort(a, n, left, mid, &nc, &nsw);
        merging_sort(a, n, mid, right, &nc, &nsw);
        merging(a, left, mid, right, &nc, &nsw);
    }
}

void menu()
{
	{
		printf("\n__________________________________________________\n");
		printf("\nMENU:\n");
		printf("1. Сгенерировать массив  \n");
		printf("\n2. Печать массива  \n");
		printf("3. Шейкерная сортировка\n");
		printf("4. Сортировка вставками\n");
		printf("5. Сортировка слиянием\n");
		printf("0. exit\n");
		printf("\n__________________________________________________\n");
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	int a[10];
	int n = 10;
	int t = 100;
	int left = 0, right = n - 1;
	LARGE_INTEGER start, finish, freq;
	double time;
	double timeAll[5];
	int nComp[5];
	int nSwaps[5];

	QueryPerformanceFrequency(&freq);

	

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			vvod_array(a, n);
			break;
		}

		case 2:
		{
			print_array(a, n);
			break;
		}
		
		case 3:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sheikere_sort(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		case 4:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			Insertion_sort(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		case 5:
		{
			int nc = 0, nsw = 0;
		    QueryPerformanceCounter(&start);
			merging_sort(a, n, left, right, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			break;
		}
		}
	}
}