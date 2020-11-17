#include "stdio.h"
#include "memory.h"

void myMalloc2(int** B, int n)
{
	// *B == int*
	*B = (int*)malloc(sizeof(int) * n); // это адрес
}

void myFree(int** B)
{
	free(*B);
}

int* myMalloc(int n)
{

	int* B2 = (int*)malloc(sizeof(int) * n);
	return B2;
}

void print(int* B, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", B[i]);
	printf("\n");
}

void randArray(int* B, int n, int a, int b)
{
	int i;
	for (i = 0; i < n; i++)
		B[i] = rand() % (b - a) + a;
}

void modify(int* B, int n)
{
	int i;
	int* tmp;
	tmp = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		tmp[i] = B[n - i] + rand() % 100;

	for (i = 0; i < n; i++)
		B[i] = tmp[i];

	free(tmp);
}

void CounterSort(int* B, int n)
{
	int max = 10, min = -3;
	int* C;
	C = myMalloc(max - min + 1);

	// сортировка


	free(C);
}

void swaplementm(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void Split(int* B, int first, int last, 
			int* l, int* r)
{
	int left = first, right = last, middle = B[(left + right) / 2];
	do
	{
		while (B[left] < middle) left++;
		while (B[right] > middle) right--;
		if (left <= right)
		{
			int tmp = B[left];
			B[left] = B[right];
			B[right] = tmp;
			left++;
			right--;
		}
	} while (left <= right);

	//это то, что возвращаем
	*l = left;
	*r = right;
}

void QuickSort(int B[], int n)
{
	int first = 0;
	int last = n - 1;
	if (first < last)
	{
		int left, right;
		Split(B, first, last, &left, &right);
		QuickSort(B, first, right);
		QuickSort(B, left, last);
	}
}

void main()
{
	int* B;
	int* B2;
	int* tmp;
	int n = 5;
	int k = 7;

	int M[100];

	B = &n; // взять адрес
	B2 = &k;
	// разыменовать
	k = *B;
	n = 15;
	printf("n %d k %d B %d *B %d\n", n, k, B, *B);

	//поменять 2 указателя
	tmp = B;
	B = B2;
	B2 = tmp;
	printf("*B %d *B2 %d\n", *B, *B2);

	//// массив произвольного размера
	//int* B[n];
	B = (int*)malloc(sizeof(int) * n);
	randArray(B, n, -10, 10);
	print(B, n);
	B2 = B;
	print(B2, n);

	// массив произвольного размера
    //int* B[n];
	B = myMalloc(n);
	randArray(B, n, -10, 10);
	print(B, n);
	B[n - 1] *= 10;
	swaplementm(&(B[0]), &(B[n - 1]));
	print(B, n);

	QuickSort(B, n);
	print(B, n);

	free(B);	

	


	//B = myMalloc(n * 2);
	//randArray(B, n * 2, -10, 10);
	//print(B, n * 2);
	//free(B);

	//
	//myMalloc2(&B2, k);
	//randArray(B2, k, -10, 10);
	//print(B2, k);

	//myFree(&B2);
}