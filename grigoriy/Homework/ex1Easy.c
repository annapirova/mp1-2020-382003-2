#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void inputSize(int* n)
{

	printf("Input size of matrix: ");
	scanf("%d", n);
	printf("\n");
	if ((*n) < 1)
		inputSize(n);
}

int* memoryAllocation(int n, int a) {
	int *array_1D = (int*) malloc(sizeof(int) * n);
	int *array_2D = (int*) malloc(sizeof(int) * n * n);
	return a == 1 ? array_1D : array_2D;
}

void print(int *array, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
}

void print_2D(int *array, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", array[i * n + j]);
		printf("\n");
	}
}

void inputRandArray(int *array, int n, int a, int b) {
	int i, j;
	srand((unsigned int) time(0));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			array[i * n + j] = rand() % (b - a) + a;
}

void rangeOfValues(int *a, int *b) {
	printf("Enter a range of values\nStart of a range: ");
	scanf("%d", a);
	printf("End of a range: ");
	scanf("%d", b);
	if ((*a) > (*b)) {
		printf(
				"\nThe beginning of the range must be less than or equal to the end of the range!\n");
		rangeOfValues(a, b);
	}
}

int sumOfMainDiagonals(int *array, int n) {
	int i, sum = 0;
	for (i = 0; i < n; i++)
		sum += array[i * n + i];

	return sum;
}

int* sd(int *array, int n) {
	int *sum;
	sum = (int*) malloc(sizeof(int) * n);
	int i, j, k;
	for (i = 1; i < n; i++) {
		k = 0;
		for (j = 0; j < n; j++) {
			if (j + i < n)
				sum[i - 1] += array[j * n + j + i];
			else {
				sum[i - 1] += array[j * n + k];
				k++;
			}
		}
	}
	return sum;
}

int main()
{
	int *matrix;
	int *sum;
	int n, min, max;

	inputSize(&n);
	sum = memoryAllocation(n, 2);
	matrix = memoryAllocation(n, 2);
	rangeOfValues(&min, &max);
	inputRandArray(matrix, n, min, max);
	print_2D(matrix, n);
	printf("\n");
	sum = sd(matrix, n);
	print(sum, n - 1);
	printf("\n");

	free(sum);
	free(matrix);
	return 0;
}
