#include "locale.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "string.h"
#include "time.h"

void swaparray(int* B, int* B2, int n, int*T)
{
	memcpy(T, B2, n * sizeof(int));

	memcpy(B2, B, n * sizeof(int));

	memcpy(B, T, n * sizeof(int));
}
void spawnarray(int** B, int n)
{
	*B = (int*)malloc(n * sizeof(int));

}
void swaplement(int* B, int i, int j)
{
	int t;
	t = B[i];
	B[i] = B[j];
	B[j] = t;
}
void Vvodmassiv(int* B, int n)
{
	printf("Введите свой массив:");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &B[i]);
	}
}
void Vivodmassiv(int* B, int n)
{
	printf("Массив оригинал:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", B[i]);
	}
	printf("\n");

}
void Randmassiv(int* B, int n)
{
	int max = 100;
	int min = 50;
	int proverka;
	printf("Введите максимальное и минимальное значения, или они будут 100 и 50\n");
	printf("Если вы согласны с изначальным, напишите 1, если нет, напишите 2\n");
	scanf_s("%d", &proverka);
	switch (proverka)
	{
	case 1: {
		printf("макс:%d мин:%d", max, min);
		int i;
		for (i = 0; i < n; i++)
			B[i] = rand() % (max - min) + min;
		break;
	}
	case 2: {
		printf("Введите свои макс. и мин.:");
		scanf_s("%d %d", &max, &min);
		printf("макс:%d мин:%d", max, min);
		int i;
		for (i = 0; i < n; i++)
			B[i] = rand() % (max - min) + min;
		break;
	}
	}
}
void BubbleSort(int *B, int n)
{
	int i, j;
	bool wasSwap = false;
	for (i = 0; i < n; i++)
	{
		wasSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (B[j] > B[j + 1])
			{
				swaplement(B, j, j + 1);
				//tmp = B[j];
				//B[j] = B[j + 1];
				//B[j + 1] = tmp;
				wasSwap = true;
			}
		}
		if (!wasSwap)
		{
			break;
		}
	}
}
void QuickSort(int *B, int first, int last)
{
	if (first < last)
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
		QuickSort(B, first, right);
		QuickSort(B, left, last);

	}
}
void InsertSort(int *B, int n)
{
	int Elementvzat, index;

	for (int i = 1; i < n; i++)
	{
		Elementvzat = B[i];

		index = i - 1;

		while (index >= 0 && B[index] > Elementvzat)
		{
			B[index + 1] = B[index];
			index = index - 1;
		}
		B[index + 1] = Elementvzat;

	}

}
void ShakerSort(int *B, int n)
{
	int left = 1;
	int right = n - 1;
	while (left <= right)
	{
		for (int i = right; i >= left; i--)
			if (B[i - 1] > B[i]) swaplement(B, i, i - 1);
		left++;

		for (int i = left; i <= right; i++)
			if (B[i - 1] > B[i]) swaplement(B, i, i - 1);
		right--;

	}
}
void ShellSort(int *B, int n)
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = B[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < B[j - step])
					B[j] = B[j - step];
				else
					break;
			}
			B[j] = tmp;
		}
}
void Slian(int *B, int i1, int j1, int i2, int j2, int j3)
{
	int* temp;
	int p = j3;
	temp = (int*)malloc(p * sizeof(int));
	int i, j, k;
	i = i1;
	j = i2;
	k = 0;

	while (i <= j1 && j <= j2)
	{
		if (B[i]<B[j])
			temp[k++] = B[i++];
		else
			temp[k++] = B[j++];
	}

	while (i <= j1)
		temp[k++] = B[i++];

	while (j <= j2)
		temp[k++] = B[j++];

	for (i = i1, j = 0; i <= j2; i++, j++)
		B[i] = temp[j];
	free(temp);
}
void SlianSort(int *B, int i, int j) {
	int middle = 1;
	if (i<j)
	{
		(int)middle = (i + j) / 2;
		SlianSort(B, i, middle);
		SlianSort(B, middle + 1, j);
		Slian(B, i, middle, middle + 1, j, j + 1);
	}
}

void menu()
{
	printf("\nМЕНЮ:\n");
	printf("1. Ввести массив\n");
	printf("2. Вывести массив\n");
	printf("3. Задать массив из рандомных чисел\n");
	printf("4. Сортировка Пузырьком\n");
	printf("5. Быстрая сортировка(Harra)\n");
	printf("6. Сортировка Вставкой\n");
	printf("7. Шейкерная сортировка\n");
	printf("8. Сортировка Шелла\n");
	printf("9. Сортировка Слиянием\n");
	printf("10. Количество элементов\n");
	printf("11. Запомнить мой массив\n");
	printf("12. Заменить мой массив, на сохранённую копию\n");
	printf("0. Выход\n");
	printf("_________________________________________________\n");
	printf("Поле ввода>>");

}

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("Программа по созданию и сортировки массивов\n");
	printf("с приминением разных методов сортировок\n");
	printf("_____________________________________________");

	int* B = NULL;
	int* B2 = NULL;
	int* T = NULL;
	int n;
	int t = 13;
	clock_t Start, Stop;

	bool wasInput1 = false;
	bool wasInput2 = false;
	bool wasInput3 = false;
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			if (wasInput1) {
				wasInput2 = true;
				Vvodmassiv(B, n);
			}
			else
				printf("ОШИБКА \n <Вы не ввели количество элементов массива>\n");
			break;
		}
		case 2:
		{
			if (wasInput2) {
				Vivodmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 3:
		{
			if (wasInput1) {
				wasInput2 = true;
				Randmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели количество элементов массива>\n");
			break;
		}
		case 4:
		{
			if (wasInput2) {
				Start = clock() * 1000 / CLOCKS_PER_SEC;
				BubbleSort(B, n);
				Stop = clock() * 1000 / CLOCKS_PER_SEC;
				printf("\nReal time for sorting %i(ms)\n", Stop - Start);
				Vivodmassiv(B, n);

			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 5:
		{
			if (wasInput2) {

				QuickSort(B, 0, n - 1);
				Vivodmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 6:
		{
			if (wasInput2) {

				InsertSort(B, n);
				Vivodmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 7:
		{
			if (wasInput2) {

				ShakerSort(B, n);
				Vivodmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 8:
		{
			if (wasInput2) {

				ShellSort(B, n);
				Vivodmassiv(B, n);
			}
			else printf("ОШИБКА \n <Вы не ввели значения массива>\n");
			break;
		}
		case 9:
		{
			if (wasInput2) {

				SlianSort(B, 0, n - 1);
				Vivodmassiv(B, n);
			}
			else printf("Вы не ввели значения массива\n");
			break;
		}
		case 10:
		{
			wasInput1 = true;
			wasInput2 = false;
			printf("Введите количество элементов массива:");
			scanf_s("%d", &n);
			spawnarray(&B, n);
			break;
		}
		case 11:
		{
			if (wasInput1)
			{
				wasInput3 = true;
				spawnarray(&B2, n);
				memcpy(B2, B, n * sizeof(int));
				Vivodmassiv(B2, n);
			}
			else printf("ОШИБКА \n <Отсутствует массив-оригинал>\n");
			break;
		}

		case 12:
		{
			if (wasInput3) {

				spawnarray(&T, n);
				swaparray(B, B2, n, T);
				printf("Оригинал заменён скопированным массивом\n");
				wasInput3 = false;
				free(T);
			}
			else printf("ОШИБКА \n <Нет массива-оригинала или копии>\n");
			break;
		}

		}
	}
	free(B);
	free(B2);
}