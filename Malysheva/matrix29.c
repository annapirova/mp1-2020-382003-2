#include <stdio.h>
#include "locale.h"
#include <malloc.h>

void malloc2(int*** a, int n)
{	
	int i;
	*a = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		(*a)[i] = (int*)malloc(sizeof(int) * n);
}

void free2(int*** A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free((*A)[i]);
	free(*A);
}

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

void carray2(int** a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
            a[i][j] = (int)(rand() % 100);
}

void umn(int** a, int* b, int* c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[i][j] * b[j];
        }
    }
}

void vect(int* b, int n)
{
    int i;
	for (i = 0; i < n; i++)
		printf("%3d \n", b[i]);
	printf("\n");
}

void print2(int** a, int n)
{
	int j, i;
	for (i = 0; i < n; i++)
    {    for(j = 0; j < n; j++)
		    printf("%3d ", a[i][j]);
	    printf("\n");}
}


void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, m, tmp;
    int** a;
    int* b = NULL;
    int* c = NULL;
    
    srand(122);

    printf("введите n \n");
    scanf("%d", &n);
    malloc2(&a, n);
    b = (int*)malloc(n * sizeof(int));
    c = (int*)malloc(n * sizeof(int));
    carray0(c, n);
    carray(b, n);
    carray2(a, n);
    printf("матрица \n");
    print2(a, n);
    printf("решение \n");
    vect(b, n);
    umn(a, b, c, n);
    printf("вектор правой части \n");
    vect(c, n);
    free2(&a, n);
    free(b);
    free(c);
}