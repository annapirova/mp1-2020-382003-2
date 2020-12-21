#include <stdio.h>
#include "locale.h"
#include <malloc.h>

void carray0(int* c, int n)
{
    int i;
    for (i = 0; i < n; i++)
		c[i] = 0;
}

void carray(int* a, int n)
{ 
    int i;
    for (i = 0; i < n; i++)
		a[i] = (int)(rand() % 100);

}

void umn(int* a, int* b, int* c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[i * n + j] * b[j];
        }
    }
}

void print2(int* a, int n)
{
    int i;
	for (i = 0; i < n; i++)
		print(&(a[i * n]), n);
}

void vect(int* b, int n)
{
    int i;
	for (i = 0; i < n; i++)
		printf("%3d \n", b[i]);
	printf("\n");
}

void print(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%3d ", a[i]);
	printf("\n");
}


void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, m, tmp;
    int* a = NULL;
    int* b = NULL;
    int* c = NULL;
    
    srand(122);

    printf("введите n \n");
    scanf("%d", &n);
    a = (int*)malloc(n * n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    c = (int*)malloc(n * sizeof(int));
    carray0(c, n);
    carray(a, n * n);
    carray(b, n);
    printf("матрица \n");
    print2(a, n);
    printf("решение \n");
    vect(b, n);
    umn(a, b, c, n);
    printf("вектор правой части \n");
    vect(c, n);
    free(a);
    free(b);
    free(c);
}