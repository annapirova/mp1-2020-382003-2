#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#include "locale.h"

void gen_array(int a[], int n)
{
	if (n <= 10) 
	{
		printf("\nВведите элементы массива: ");
		for (int i = 0; i < n; i++) 
		{
			scanf_s("%d", &a[i]);
		}
	}
	else 
	{
		for (int i = 0; i < n; i++) 
		{
			a[i] = rand() % 1000;
		}
	}
}

void copy_array(int a[], int tmp_a[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		tmp_a[i] = a[i];
	}
}

void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void shaker_sort(int a[], int n, int* nc, int* nsw)
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

void  insertion_sort(int a[], int n, int* nc, int* nsw)
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
	int* tmp_a = (int*)malloc((right - left + 1) * sizeof(int));
	int i, l1 = 0, l2 = 0;

	*nc = *nc + 1;
	while ((left + l1 < mid) && (mid + l2 < right))
	{
		*nc = *nc + 1;
		if (a[left + l1] < a[mid + l2])
		{
			tmp_a[l1 + l2] = a[left + l1];
			l1++;
			*nsw = *nsw + 1;
		}
		else
		{
			tmp_a[l2 + l1] = a[mid + l2];
			l2++;
			*nsw = *nsw + 1;
		}
	}

	*nc = *nc + 1;
	while (left + l1 < mid)
	{
		tmp_a[l1 + l2] = a[left + l1];
		l1++;
		*nsw = *nsw + 1;
	}

	*nc = *nc + 1;
	while (l2 + mid < right)
	{
		tmp_a[l1 + l2] = a[mid + l2];
		l2++;
		*nsw = *nsw + 1;
	}

	for (i = 0; i < l1 + l2; i++)
	{
		a[left + i] = tmp_a[i];
		*nsw = *nsw + 1;
	}
	free(tmp_a);
}

void merging_sort(int a[], int left, int right, int* nc, int* nsw)
{
	int mid;

	*nc = *nc + 1;
	if (left + 1 < right)
	{
		mid = (left + right) / 2;
		merging_sort(a, left, mid, &nc, &nsw);
		merging_sort(a, mid, right, &nc, &nsw);
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

int main()
{
	setlocale(LC_ALL, "rus");
	int* a = NULL;
	int* tmp_a = NULL;
	int n;
	int t = 100;
	int left, right;
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
			free(a);
			free(tmp_a);
			printf("Введите размер массива: ");
			scanf_s("%d", &n);

			a = (int*)malloc(n * sizeof(int));
			tmp_a = (int*)malloc(n * sizeof(int));
			gen_array(a, n);
			copy_array(a, tmp_a, n);
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
			shaker_sort(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			copy_array(tmp_a, a, n);
			break;
		}
		case 4:
		{
			int nc = 0, nsw = 0;
			QueryPerformanceCounter(&start);
			insertion_sort(a, n, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			copy_array(tmp_a, a, n);
			break;
		}
		case 5:
		{
			int nc = 0, nsw = 0;
			left = 0;
			right = n;
			QueryPerformanceCounter(&start);
			merging_sort(a, left, right, &nc, &nsw);
			print_array(a, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			timeAll[0] = time;
			nSwaps[0] = nsw;
			nComp[0] = nc;
			printf("\ntime = %lf\n", time);
			printf("swaps %d comparisons %d\n", nsw, nc);
			copy_array(tmp_a, a, n);
			break;
		}
		}
	}
	free(a);
	free(tmp_a);

	return 0;
}
