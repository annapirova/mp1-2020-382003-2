#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

void swaplementm(int B[], int i)
{
	int t;
	t = B[i];
	B[i] = B[i - 1];
	B[i - 1] = t;
}
void swaplementp(int B[], int j)
{
	int t;
	t = B[j];
	B[j] = B[j + 1];
	B[j + 1] = t;
}
void Vvodmassiv(int B[],int n) 
{
	printf("Vvodite svoi massive:");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &B[i]);
	}
}
void Vivodmassiv(int B[], int n)
{
	printf("Vash massive:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", B[i]);
	}
	printf("\n");
}
void Randmassiv(int B[], int n)
{
	int max = 100;
	int min = 50;
	int proverka;
	printf("Vvedite max and min,or oni budut vibrani 100 and 50\n");
	printf("If vi soglasni s max and min, napishite 1, else, napishite 2\n");
	scanf_s("%d", &proverka);
	switch (proverka)
{
	case 1: {
		printf("max:%d min:%d", max, min);
		int i;
		for (i = 0; i < n; i++)
			B[i] = rand() % (max - min) + min;
		break;
	}
	case 2: {
		printf("Vvedite svoi max and min:");
		scanf_s("%d %d", &max, &min);
		printf("max:%d min:%d", max, min);
		int i;
		for (i = 0; i < n; i++)
			B[i] = rand() % (max - min) + min;
		break;
	}
}
	}
void BubbleSort(int B[], int n) 
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
				swaplementp(B, j);
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
void QuickSort(int B[], int n )
{
	int first = 0;
	int last = n - 1;
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
void InsertSort(int B[], int n)
{
	int Elementvzat, index;

	for (int i = 1; i < n; i++)
	{
		Elementvzat = B[i];

		index = i - 1;
		//printf("\n Elementvzat: %d \n i=%d  \n index=%d \n", Elementvzat, i, index);
		while (index >= 0 && B[index] > Elementvzat)
		{
			B[index + 1] = B[index];
			index = index - 1;
		}
		B[index + 1] = Elementvzat;
		//printf("\n");
		/*for (int i = 0; i < n; i++)
		{
			printf(" %d ", B[i]);
		}*/
	}

}
void ShakerSort(int B[], int n) 
{
		int left = 1;
		int right = n - 1;
		while (left <= right)
		{
			for (int i = right; i >= left; i--)
				if (B[i - 1] > B[i]) swaplementm(B, i);
			left++;

			for (int i = left; i <= right; i++)
				if (B[i - 1] > B[i]) swaplementm(B, i);
			right--;

		}
}
void ShellSort(int B[], int n)
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
void SlianSort(int B[] , int lowIndex, int highIndex) {
		if (lowIndex == highIndex)
			return;
		else {
			int midIndex = (lowIndex + highIndex) / 2;
			SlianSort(B, lowIndex, midIndex);
			SlianSort(B, midIndex + 1, highIndex);
			SlianSort(B, lowIndex, midIndex, highIndex);
		}
	}


void menu()
{
	printf("\nMENU:\n");
	printf("1. Vvesti massive\n");
	printf("2. Vosproizvesti massive\n");
	printf("3. Randomny massive\n");
	printf("4. Bubble Sortirovka\n");
	printf("5. Quick Sortirovka (Harra)\n");
	printf("6. Insert Sortirovka\n");
	printf("7. Shaker Soritrovka\n");
	printf("8. Shell Sortirovka\n");
	printf("9. Sliyanie Sortirovka\n");
	printf("0. Exit\n");
}

void main()
{
	int B[10];
	int n = 10;
	int t = 10;
	bool wasInput = false;
	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
			case 1:
			{
				Vvodmassiv(B, n);
				wasInput = true;
				break;
			}
			case 2:
			{
					if (wasInput) {
						Vivodmassiv(B, n);
				}
					else printf("Vvedi massive blen\n");
				break;
				}
			case 3:
			{
					Randmassiv(B, n);
					wasInput = true;
					break;
				}
			case 4:
			{
					if (wasInput) {

						BubbleSort(B,n);
						Vivodmassiv(B,n);
					}
					else printf("Vvedi massive blen\n");
					break;
				}
			case 5:
			{
				if (wasInput) {

				QuickSort(B, n);
				Vivodmassiv(B, n);
			}
			else printf("Vvedi massive blen\n");
			break;
			}
			case 6:
			{
				if (wasInput) {

					InsertSort(B, n);
					Vivodmassiv(B, n);
				}
				else printf("Vvedi massive blen\n");
				break;
			}
			case 7:
			{
				if (wasInput) {

					ShakerSort(B, n);
					Vivodmassiv(B, n);
				}
				else printf("Vvedi massive blen\n");
				break;
			}
			case 8:
			{
				if (wasInput) {

					ShellSort(B, n);
					Vivodmassiv(B, n);
				}
				else printf("Vvedi massive blen\n");
				break;
			}
			case 9:
			{
				if (wasInput) {

					SlianSort(B, 0, n-1);
					Vivodmassiv(B, n);
				}
				else printf("Vvedi massive blen\n");
				break;
			}
		}
	}
}