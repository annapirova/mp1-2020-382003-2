#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
#include "string.h"
#include "sys/time.h"

void menu()
{
	printf("\nMENU:\n");
	printf("1. Input user array\n");
	printf("2. Input random array\n");
	printf("3. Print array\n");
	printf("4. Bubble Sort\n"); 		// O(n^2)
	printf("5. Shake Sort\n"); 		// O(n^2)
	printf("6. Insert Sort\n");		// O(n^2)
	printf("7. Shell Sort\n"); 		// O(nlog^2n)
	printf("8. Merge Sort\n");		// O(nlogn)
	printf("9. Quick Sort\n");		// O(nlogn)
	printf("10. Count Sort\n");		// O(n+k)
	printf("11. Binary Search\n");
	printf("12. Linear Search\n");
	printf("13. Compare results\n");
	printf("0. Exit\n\n");
}

void inputUserArray(int *array, int n)
{

	int i;
	printf("\nInput values for array: ");
	for (i = 0; i < n; i++)
		scanf("%d", &array[i]);
}

void inputRandArray(int *array, int n, int a, int b)
{

	int i;
	srand((unsigned int) time(0));

	for (i = 0; i < n; i++)
		array[i] = rand() % (b - a) + a;
}

void print(int *array, int n)
{

	int i;

	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void bubbleSort(int *array, int n, int *nc, int *nsw)
{

	int i, j, tmp;
	bool f = true;

	(*nc)++;
	i = 0;
	while (i < n && f)
	{
		f = false;
		(*nc)++;
		for (j = 0; j < n - i - 1; j++)
		{
			(*nc) += 2;
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				(*nsw) += 3;
				f = true;
			}
		}
		i++;
	}
}

void shakeSort(int *array, int n, int *nc, int *nsw)
{

	int i, j, tmp, l, r;
	l = 0;
	r = n - 1;
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		(*nc) += 2;
		if (i % 2 == 0)
		{
			(*nc)++;
			for (j = l; j < r; j++)
			{
				(*nc) += 2;
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					(*nsw) += 3;
				}
			}
			r--;
		}
		else
		{
			(*nc)++;
			for (j = r; j > l; j--)
			{
				(*nc) += 2;
				if (array[j] < array[j - 1])
				{
					tmp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = tmp;
					(*nsw) += 3;
				}
			}
			l++;
		}
	}

}

void insertSort(int *array, int n, int *nc, int *nsw)
{

	int i, j, tmp;

	(*nc)++;
	for (i = 1; i < n; i++)
	{
		tmp = array[i];
		j = i - 1;

		(*nc) += 3;
		while (j >= 0 && array[j] > tmp)
		{
			array[j + 1] = array[j];
			j--;
			(*nc) += 2;
			(*nsw)++;
		}
		array[j + 1] = tmp;
		(*nsw)++;
	}
}

void shellSort(int *array, int n, int *nc, int *nsw)
{

	int i, j, tmp, step;

	(*nc)++;
	for (step = (int) (n / 2); step > 0; step /= 2)
	{
		(*nc)++;
		for (i = step; i < n; i++)
		{
			tmp = array[i];
			j = i - step;
			(*nc) += 3;
			while (j >= 0 && array[j] > tmp)
			{
				array[j + step] = array[j];
				j -= step;
				(*nc) += 2;
				(*nsw)++;
			}
			array[j + step] = tmp;
			(*nsw)++;
		}
	}
}

void merge(int *array, int l, int middle, int r, int *nc, int *nsw)
{

	int i, j, k;
	int size_l = middle - l + 1;
	int size_r = r - middle;
	int L[size_l], R[size_r];

	(*nc)++;
	for (i = 0; i < size_l; i++)
	{
		L[i] = array[l + i];
		(*nc)++;
		(*nsw)++;
	}
	(*nc)++;
	for (j = 0; j < size_r; j++)
	{
		R[j] = array[middle + 1 + j];
		(*nc)++;
		(*nsw)++;
	}

	i = 0;
	j = 0;
	k = l;
	(*nc) += 2;
	while (i < size_l && j < size_r)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
		(*nc) += 3;
		(*nsw)++;
	}
	(*nc)++;
	while (i < size_l)
	{
		array[k] = L[i];
		i++;
		k++;
		(*nc)++;
		(*nsw)++;
	}
	(*nc)++;
	while (j < size_r)
	{
		array[k] = R[j];
		j++;
		k++;
		(*nc)++;
		(*nsw)++;
	}

}

void mergeSort(int *array, int l, int r, int *nc, int *nsw)
{

	(*nc)++;
	if (l < r)
	{
		int middle = l + (int) ((r - l) / 2);
		mergeSort(array, l, middle, nc, nsw);
		mergeSort(array, middle + 1, r, nc, nsw);
		merge(array, l, middle, r, nc, nsw);
	}
}

void quickSort(int *array, int l, int r, int *nc, int *nsw)
{

	int i, j, middleValue, tmp;
	i = l;
	j = r;
	middleValue = array[(int) ((l + r) / 2)];

	(*nc)++;
	while (i < j)
	{
		(*nc)++;
		while (array[i] < middleValue)
		{
			i++;
			(*nc)++;
		}
		(*nc)++;
		while (array[j] > middleValue)
		{
			j--;
			(*nc)++;
		}
		(*nc)++;
		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
			(*nsw) += 3;
		}
	}
	(*nc)++;
	if (l < j)
		quickSort(array, l, j, nc, nsw);
	(*nc)++;
	if (i < r)
		quickSort(array, i, r, nc, nsw);
}

void countSort(int *array, int n, int *nc, int *nsw)
{

	int i, j, k, max, min;
	k = 0;
	max = 0;
	min = 0;

	for (i = 0; i < n; i++)
	{
		max = (array[i] > max) ? array[i] : max;
		min = (array[i] < min) ? array[i] : min;
	}
	int tmpArray[max - min + 1];

	(*nc)++;
	for (i = 0; i < max - min + 1; i++)
	{
		tmpArray[i] = 0;
		(*nc)++;
		(*nsw)++;
	}
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		tmpArray[array[i] - min]++;
		(*nc)++;
	}
	printf("\n");
	(*nc)++;
	for (i = 0; i < max - min + 1; i++)
	{
		(*nc) += 2;
		for (j = 0; j < tmpArray[i]; j++)
		{
			array[k] = i + min;
			k++;
			(*nc)++;
			(*nsw)++;
		}
	}
}

int binarySearch(int *array, int l, int r, int key, int *nc)
{

	int m;
	bool flag = false;

	(*nc) += 2;
	while (l <= r && flag == false)
	{
		m = l + (int) ((r - l) / 2);

		if (key < array[m])
			return binarySearch(array, l, m - 1, key, nc);
		else if (key > array[m])
			return binarySearch(array, m + 1, r, key, nc);
		else
			flag = true;
		(*nc) += 4;
	}
	return flag ? m : -1;

}

int linearSearch(int *array, int n, int key, int *nc)
{

	int pos = 0;
	bool flag = false;
	;

	(*nc) += 2;
	while (pos < n && flag == false)
	{
		if (array[pos] != key)
			pos++;
		else
			flag = true;
		(*nc) += 3;
	}
	return (pos == n) ? -1 : pos;
}

void inputSize(int *n)
{

	printf("Input size of array from 1 to 100000: ");
	scanf("%d", n);
	if ((*n) < 1 || (*n) > 100000)
		inputSize(n);
}

int* memoryAllocation(int n)
{

	int *array = (int*) malloc(sizeof(int) * n);
	return array;
}

void rangeOfValues(int *a, int *b)
{

	printf("Enter a range of values\nStart of a range: ");
	scanf("%d", a);
	printf("End of a range: ");
	scanf("%d", b);
	(*b)++;
	if ((*a) > (*b))
	{
		printf(
				"\nThe beginning of the range must be less than or equal to the end of the range!\n");
		rangeOfValues(a, b);
	}
}

bool isCorrect(int *array, int n)
{

	bool f = true;
	int i = 0;

	while (i < n - 1 && f)
	{
		if (array[i] > array[i + 1])
			f = false;
		i++;
	}

	return f;
}

double portableGetTime()
{

	struct timeval t;
	gettimeofday(&t, 0);
	return (t.tv_sec * 1000000ULL + t.tv_usec) * 1.0e-6;
}

void setMinusOneArray_int(int *array, int n)
{

	int i;
	for (i = 0; i < n; i++)
		array[i] = -1;
}

void setMinusOneArray_double(double *array, int n)
{

	int i;
	for (i = 0; i < n; i++)
		array[i] = -1;
}

void compareArrays(char **arrays, int *ncArray, int *nswArray, double *tArray,
		int n)
{

	int i;
	printf("\nSorts\t\tComparison\tSwap\tTime\n\n");

	for (i = 0; i < n; i++)
	{
		printf("%s\t\t%d\t\t%d\t%lf\n", arrays[i], ncArray[i], nswArray[i],
				tArray[i]);
	}
}

int main()
{

	int *A;
	int *Acopy;
	int nComparisonInArray[7], nComparisonInSearch[2], nSwapsInArray[7];
	double sortTime[7];
	char *sorts[] =
	{ "Bubble", "Shake", "Insert", "Shell", "Merge", "Quick", "Count" };
	bool wasInput, wasSorted;
	unsigned int num;
	int key, n, startRange, endRange, nc, nsw, nLin, nPrint;
	double start, finish;
	wasInput = false;
	wasSorted = false;

	printf("start\n");

	do
	{
		menu();
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			inputSize(&n);
			A = memoryAllocation(n);
			Acopy = memoryAllocation(n);
			inputUserArray(A, n);
			wasInput = true;
			setMinusOneArray_int(nComparisonInArray, 7);
			setMinusOneArray_int(nComparisonInSearch, 2);
			setMinusOneArray_int(nSwapsInArray, 7);
			setMinusOneArray_double(sortTime, 7);
			break;
		}
		case 2:
		{
			inputSize(&n);
			A = memoryAllocation(n);
			Acopy = memoryAllocation(n);
			rangeOfValues(&startRange, &endRange);
			inputRandArray(A, n, startRange, endRange);
			wasInput = true;
			setMinusOneArray_int(nComparisonInArray, 7);
			setMinusOneArray_int(nComparisonInSearch, 2);
			setMinusOneArray_int(nSwapsInArray, 7);
			setMinusOneArray_double(sortTime, 7);
			break;
		}
		case 3:
		{
			if (wasInput)
			{
				do
				{
					printf(
							"\nDo you want print default(1), modificated(2) or both(3) array: ");
					scanf("%d", &nPrint);
				} while (nPrint < 1 && nPrint > 3);
				switch (nPrint)
				{
				case 1:
				{
					printf("\nDefault array:");
					print(A, n);
					break;
				}
				case 2:
				{
					if (wasSorted)
					{
						printf("\nModificated array:");
						print(Acopy, n);
					}
					else
					{
						printf("\nNull array:");
						print(Acopy, n);
					}
					break;
				}
				case 3:
				{
					printf("\nDefault array:");
					print(A, n);
					if (wasSorted)
					{
						printf("\n\nModificated array:");
						print(Acopy, n);
					}
					else
					{
						printf("\n\nNull array:");
						print(Acopy, n);
					}
				}
				}
			}
			else
				printf("Input array!\n");
			break;
		}
		case 4:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				bubbleSort(Acopy, n, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[0] = finish - start;
				nComparisonInArray[0] = nc;
				nSwapsInArray[0] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[0], nComparisonInArray[0], nSwapsInArray[0],
						sortTime[0], isCorrect(Acopy, n));
			}

			else
				printf("Input array!\n");
			break;
		}
		case 5:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				shakeSort(Acopy, n, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[1] = finish - start;
				nComparisonInArray[1] = nc;
				nSwapsInArray[1] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[1], nComparisonInArray[1], nSwapsInArray[1],
						sortTime[1], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}
		case 6:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				insertSort(Acopy, n, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[2] = finish - start;
				nComparisonInArray[2] = nc;
				nSwapsInArray[2] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[2], nComparisonInArray[2], nSwapsInArray[2],
						sortTime[2], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}
		case 7:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				shellSort(Acopy, n, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[3] = finish - start;
				nComparisonInArray[3] = nc;
				nSwapsInArray[3] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[3], nComparisonInArray[3], nSwapsInArray[3],
						sortTime[3], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}
		case 8:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				mergeSort(Acopy, 0, n - 1, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[4] = finish - start;
				nComparisonInArray[4] = nc;
				nSwapsInArray[4] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[4], nComparisonInArray[4], nSwapsInArray[4],
						sortTime[4], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}
		case 9:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				quickSort(Acopy, 0, n - 1, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[5] = finish - start;
				nComparisonInArray[5] = nc;
				nSwapsInArray[5] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[5], nComparisonInArray[5], nSwapsInArray[5],
						sortTime[5], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}
		case 10:
		{
			if (wasInput)
			{
				memcpy(Acopy, A, sizeof(int) * n);
				nc = 0;
				nsw = 0;
				start = portableGetTime();
				countSort(Acopy, n, &nc, &nsw);
				finish = portableGetTime();
				wasSorted = true;
				sortTime[6] = finish - start;
				nComparisonInArray[6] = nc;
				nSwapsInArray[6] = nsw;
				printf(
						"\n%s sort\nComparison: %d, Swaps: %d, Time: %lf, Correct: %d\n",
						sorts[6], nComparisonInArray[6], nSwapsInArray[6],
						sortTime[6], isCorrect(Acopy, n));
			}
			else
				printf("Input array!\n");
			break;
		}

		case 11:
		{
			if (wasInput)
			{
				if (wasSorted)
				{
					nc = 0;
					printf("\nEnter a key: ");
					scanf("%d", &key);
					printf("\nBinary search");
					if (binarySearch(Acopy, 0, n - 1, key, &nc) != -1)
						printf("\nThe key '%d' is found!\n", key);
					else
						printf("\nThe key '%d' is not found!\n", key);
					nComparisonInSearch[0] = nc;
					printf("Comparison: %d\n", nComparisonInSearch[0]);
				}
				else
					printf("Sort array!\n");
			}
			else
				printf("Input array!\n");
			break;
		}
		case 12:
		{
			if (wasInput)
			{
				nc = 0;
				printf("\nEnter a key: ");
				scanf("%d", &key);
				do
				{
					printf("\nDo you want use default(1) or sorted(2) array: ");
					scanf("%d", &nLin);
				} while (nLin < 1 && nLin > 2);
				printf("\nLinear search");
				switch (nLin)
				{
				case 1:
				{
					if (linearSearch(A, n, key, &nc) != -1)
						printf("\nThe key '%d' is found!\n", key);
					else
						printf("\nThe key '%d' is not found!\n", key);
					break;
				}
				case 2:
				{
					if (linearSearch(Acopy, n, key, &nc) != -1)
						printf("\nThe key '%d' is found!\n", key);
					else
						printf("\nThe key '%d' is not found!\n", key);
					break;
				}
				}
				nComparisonInSearch[1] = nc;
				printf("Comparison: %d\n", nComparisonInSearch[1]);
			}
			else
				printf("Input array!\n");
			break;
		}
		case 13:
		{
			compareArrays(sorts, nComparisonInArray, nSwapsInArray, sortTime,
					7);
			break;
		}

		case 0:
		{
			printf("\nstop\n");
			break;
		}
		default:
			printf("\nEnter integer from 0 to 13!\n");
		}
	} while (num != 0);
	free(A);
	free(Acopy);

	return 0;
}
