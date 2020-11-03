#define _USE_MATH_DEFINES
#include "math.h"
#include "stdio.h"
#include "locale.h"
#include "stdlib.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[1000] = { 101, 102, 201, 501, 505 }, index[10], G[1000], B[1000], count[1000];
	int n = 5, i = 0, h = 0, min = 10000;
	int no;
	int j, p, m, s, k;
	printf("¬ведите трехзначный массив - ");
	//for (i = 0; i < n; i++)
	//	scanf_s("%d", &A[i]);

	for (i = 0; i < n; i++)
		if (A[i] < min)
			min = A[i];
	for (i = 0; i < 1000; i++)
		count[i] = 0;
	for (i = 0; i < 1000; i++)
		B[i] = 0;
	for (i = 0; i < n; i++)
		count[A[i] - min]++;
	m = 0;
	for (i = 0; i < 1000; i++)
		if (count[i] != 0)
		{
			B[m] = min + i;
			m++;
		}




	/*for (i = 0; i <= 9; i++)
		index[i] = 0;*/

	index[0] = 0;
	k = 0;

	for (i = 0; i < n - 1; i++)
	{
		if (((B[i + 1] / 100) - (B[i] / 100)) != 0)
		{
			k++;
			index[k] = i + 1;
		}
	}
	k++;
	index[k] = n;

	printf("indexes: ");
	for (i = 0; i < k; i++)
		printf("%d\t", index[i]);
	printf("\n");

	h = 0;
	for (i = 0; i < k; i++)
	{
		G[h] = -1;
		for (j = index[i]; j < index[i + 1] - 1; j++)
		{
			s = B[j + 1] - B[j];
			if (s > 1)
			{
				G[h] = B[j] + 1;
				h++;
			}
		}
		if (G[h] == -1)
			if (index[i + 1] - index[i] > 1)
			{
				G[h] = B[j] + 1;
				h++;
			}
			else
			{
				int f = min(B[j] + 1, B[j] / 100 * 100 + 1);
				if (f == B[j]) f++;
				G[h] = f;
				h++;
			}
	}
	//for (i = 0; i < n; i++)
	//	printf("%d\t", B[i]);
	//for (i = 0; i < n; i++)
	//	printf("%d\t", G[i]);

	printf("results: ");
	for (i = 0; i < h; i++)
		printf("%d\t", G[i]);
}