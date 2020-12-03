#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void inputSize(int *n) {

	printf("Input number of students: ");
	scanf("%d", n);
	printf("\n");
	if ((*n) < 0)
		inputSize(n);
}

void inputRandArray(int *array, int n, int m) {
	int i, j;
	srand((unsigned int) time(0));

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			array[i * n + j] = rand() % 5 + 1;
}

void inputRandArray_2D(int **array, int n, int m) {
	int i, j;
	srand((unsigned int) time(0));

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			array[i][j] = rand() % 5 + 1;
}

int* memoryAllocation(int n, int m) {
	int *array = (int*) malloc(sizeof(int) * m * n);
	return array;
}

int** memoryAllocation_2D(int n, int m) {
	int i;
	int **array = (int**) malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		array[i] = (int*) malloc(sizeof(int) * m);
	return array;
}

void print(int *array, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", array[i * n + j]);
		printf("\n");
	}
}

void print_2D(int **array, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
}

void sc(int *res, int n, int *ar) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			switch (res[i * 3 + j])
			{
			case 1:
				{
				ar[j * 3]++;
				break;
			}
			case 2:
				{
				ar[j * 3 + 1]++;
				break;
			}
			case 3:
				{
				ar[j * 3 + 2]++;
				break;
			}
			case 4:
				{
				ar[j * 3 + 3]++;
				break;
			}
			case 5:
				{
				ar[j * 3 + 4]++;
				break;
			}
		}
		}
	}
}

void sc_2D(int **res, int n, int **ar) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			switch (res[i][j]) {
			case 1: {
				ar[j][0]++;
				break;
			}
			case 2: {
				ar[j][1]++;
				break;
			}
			case 3: {
				ar[j][2]++;
				break;
			}
			case 4: {
				ar[j][3]++;
				break;
			}
			case 5: {
				ar[j][4]++;
				break;
			}
			}

		}
	}
}

void compare(int *array) {
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("\n\tExam №%d\n\n", i + 1);
		for (j = 0; j < 5; j++)
			printf("%d:%d ", j + 1, array[i * 3 + j]);
	}
}

void compare_2D(int **array) {
	int i, j;
	for (i = 0; i < 3; i++)
		{
		printf("\n\n\tExam №%d\n\n", i + 1);
		for (j = 0; j < 5; j++)
			printf("%d:%d ", j + 1, array[i][j]);
	}
}

void zero(int *array, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			array[i * m + j] = 0;
}

void zero_2D(int **array, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			array[i][j] = 0;
}

void free_2D(int ***array, int n) {
	int i;
	for (i = 0; i < n; i++)
		free((*array)[i]);
	free(*array);
}

int main() {
	int n;
	/*
	int *results;  //'DOESN'T WORK CORRECTLY WITH THE LINEAR REPRESENTATION'
	int *score;

	inputSize(&n);
	results = memoryAllocation(n, 3);
	score = memoryAllocation(3, 5);
	inputRandArray(results, n, 3);
	zero(score, 3, 5);
	print(results, n, 3);
	sc(results, n, score);
	compare(score);
	 free(score);
	 free(results);*/
	
	int **results;
	int **score;

	inputSize(&n);
	results = memoryAllocation_2D(n, 3);
	score = memoryAllocation_2D(3, 5);
	inputRandArray_2D(results, n, 3);
	zero_2D(score, 3, 5);
	print_2D(results, n, 3);
	sc_2D(results, n, score);
	compare_2D(score);
	free_2D(&results, n);
	free_2D(&score, 3);
	return 0;
}
