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

void vvod_array1(int a[], int n)
{
    int i;

    printf("enter an array of integers\n");

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
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

void sort1(int a[], int n, int* nc, int* nsw)
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

void sort2(int a[], int n, int* nc, int* nsw)
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
        if (a[left + i1] < a[mid + l2])
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

void sort3(int a[], int n, int left, int right, int *nc, int *nsw)
{
    int mid;

	*nc = *nc + 1;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        sort3(a, n, left, mid, &nc, &nsw);
        sort3(a, n, mid, right, &nc, &nsw);
        merging(a, left, mid, right, &nc, &nsw);
    }
}

void linear_search(int a[], int n, int* nc)
{
	int k;
	int pos = -1;
	int i;

	printf("enter the number, which need to find\n");
	scanf_s("%d", &k);

	for (i = 0; i < n; i++)
	{
		*nc = *nc + 1;
		if (a[i] == k)
		{
			printf("ýelement %d is in position %d\n", k, i + 1);
			break;
		}
	}
	*nc = *nc + 1;
	if (i == n)
		printf("element %d isn't found in array\n", k);
}

void binary_search(int a[], int n, int* nc)
{
	int k;
	int left, right, mid;

	printf("enter the number, which need to find\n");
	scanf_s("%d", &k);

	left = 0;
	right = n - 1;
	mid = (left + right) / 2;

	*nc = *nc + 1;
	while (left <= right)
	{
		*nc = *nc + 1;
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else
			*nc = *nc + 1;
		if (a[mid] == k)
		{
			printf("element %d is in position %d .\n", k, mid + 1);
			break;
		}
		else
			right = mid - 1;
		mid = (left + right) / 2;
	}
	*nc = *nc + 1;
	if (left > right)
		printf("element %d isn't found in array\n", k);
}

void menu()
{
	{
		printf("\n__________________________________________________\n");
		printf("\nMENU:\n");

		printf("\nchoose array input method\n");
		printf("1. generate new array  \n");
		printf("2. enter an array manually \n");

		printf("\n3. print array  \n");

		printf("\nchoose the way how to search elements\n");
		printf("4. linear search\n");
		printf("5. binary search (only if array already was sorted)\n");

		printf("\nchoose the sort method\n");
		printf("6. sheiker sort\n");
		printf("7. insert sort\n");
		printf("8. merge sort\n");
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
			vvod_array1(a, n);
			break;
		}
		case 3:
		{
			print_array(a, n);
			break;
		}
		case 4:
		{
			int nc = 0;
			QueryPerformanceCounter(&start);
			linear_search(a, n, &nc);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("comparisons %d\n", nc);
			break;
		}
		case 5:
		{
			int nc = 0;
			QueryPerformanceCounter(&start);
			binary_search(a, n, &nc);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("comparisons %d\n", nc);
			break;
		}
		case 6:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort1(a, n, &nc, &nsw);
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
		case 7:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort2(a, n, &nc, &nsw);
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
		case 8:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			sort3(a, n, left, right, &nc, &nsw);
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
