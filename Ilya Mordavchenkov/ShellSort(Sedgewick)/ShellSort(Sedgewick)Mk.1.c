// Сортировка Шелла с приращениями из  последовательности, которую придлажил Роберт Седжвик.
#include"stdio.h"
#include"locale.h"
#include"stdbool.h"
#include"math.h"

void menu()
{
	printf("\nMENU:\n");
	printf("1. Ввести размер массива:\n");
	printf("2. Ввести элементы массива:\n");
	printf("3. Отсортировать массив\n");
	printf("4. Распечатать массив\n");
	printf("0. Завершить работу программы\n");
}

int Size_f(int Size)
{
	printf("Введите размер массива:");
	scanf_s("%d", &Size);
	return Size;
}

void input(int A[], int Size)
{
	int i;
	printf("Введите элементы массива:");
	for (i = 0; i < Size; i++)
	{
		scanf_s("%d", &A[i]);
	}
}

void print(int A[], int Size)
{
	int i;
	for (i = 0; i < Size; i++)
	{
		printf("%d\t", A[i]);
	}
}

int increments(int inc[], int Size)
{
	int i;
	inc[0] = 1;
	for (i = 1; (3 * inc[i-1]) < Size; i++)
	{
		if (i % 2)
		{
			inc[i] = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
		}
		else inc[i] = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
	}
	return i-2;
}
void ShellSort(int A[], int Size)
{
	int inc[100];
	int S,i,counter,tmp;
	for (i = 0; i < 100; i++)
	{
		inc[i] = 0;
	}
	S = increments(inc,Size);
	for (S; S >= 0; S--)
	{
		for (i = inc[S]; i < Size; i++)
		{
			counter = i;
			tmp = A[i];
			while ((counter - inc[S] >= 0) && (tmp > A[counter - inc[S]]))
			{
				A[counter] = A[counter - inc[S]];
				counter-= inc[S];
			}
			A[counter] = tmp;
		}
	}
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[100];
	int Size=0, i, t=1;
	bool SizeInput = false;
	bool MassInput = false;
	while (t)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			Size = Size_f(Size);
			SizeInput = true;
			break;
		}
		case 2:
		{
			if (SizeInput)
			{
				input(A, Size);
				MassInput = true;
			}
			else printf("Введите размер массива!");
			break;
		}
		case 3:
		{
			if (MassInput)
			{
				ShellSort(A, Size);
			}
			else printf("Error");
			break;
		}
		case 4:
		{
			if (MassInput)
			{
				print(A, Size);
			}
			else printf("Error");
			break;
		}
		}
	}

}