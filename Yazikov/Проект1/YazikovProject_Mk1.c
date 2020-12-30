#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int Binar_search(int *A, int n)
{                                  
	int key, med;
	int left = 0;                    
	int right = n;
	printf("Введите элемент для поиска\n");
	scanf_s("%d", &key);
	while (left < right - 1)            
	{
		med = (left + right) / 2;         
		if (A[med] < key)
			left = med;
		else
			right = med;                
	}
	if (A[right]==key)
		return right;
	else return -1;
}

int Linear_search(int *A, int n)
{
	int i, p;
	int sw = 0;
	printf("Введите элемент для поиска\n");
	scanf_s("%d", &p);
	for (i = 0; i < n; i++)
	{
		if (A[i] == p)
		{
			return i;
			break;
		}
	}
		return -1;
}

void Count_sort(int *A, int n, int a, int b, int *comp, int *assign)
{
	int co = 0;
	int as = 0;
	int i,j;
	int *R = (int*)malloc((b - a + 1) * sizeof(int));
	for (i = 0; i < (b - a); i++)
		R[i] = 0;
	for (i = 0; i < n; i++)
	{
		R[A[i] - a]++;
		A[i] = 0; as++;
	}
	j = 0;
	for (i = 0; i < (b - a); i++)
	{
		while (R[i] > 0)
		{
			A[j] = (i + a);
			j++;
			R[i]--; as++;
		}
	}
	free(R);
	*assign = as;
	*comp = co;
}

int* Merge_sort(int *X, int *Y, int a, int b, int *comp, int *assign)
{
	int co = 0;
	int as = 0;
	int mid;
	if (a == b)
	{
		Y[a] = X[a];
		return Y;
	}
	mid = (a + b) / 2;
	int *left = Merge_sort(X, Y, a, mid, &co, &as);
	int *right = Merge_sort(X, Y, mid + 1, b, &co, &as);

	int *target = left == X ? Y : X;

	int l_cur = a, r_cur = mid + 1;
	for (int i = a; i <= b; i++)
	{
		if (l_cur <= mid && r_cur <= b)
		{
			co++;
			if (left[l_cur] < right[r_cur])
			{
				target[i] = left[l_cur];
				l_cur++;
				as++;
			}
			else
			{
				as++;
				target[i] = right[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= mid)
		{
			target[i] = left[l_cur]; as++;
			l_cur++;
		}
		else
		{
			target[i] = right[r_cur];
			r_cur++; as++;
		}
	}
	*assign += as;
	*comp += co;
	return target;
}

//void SortBubble(int* A, int n)
//{
//	int tmp, i, j;
//	char bl;
//	for (i = 0; i < n; i++)
//	{
//		bl = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (A[j + 1] < A[j])
//			{
//				tmp = A[j + 1];
//				A[j + 1] = A[j];
//				A[j] = tmp;
//				bl = 1;
//			}
//		}
//		if (bl = 0)
//			break;
//	}
//}

void SortBubble(int* A, int n, int *comp, int *assign)
{
	int left = 0; 
	int right = n-1;
	int bl = 1;
	int i, sw;
	int co = 0;
	int as = 0;
	while ((right > left) && (bl > 0))
	{
		bl = 0;
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
			{
				sw = A[i];
				A[i] = A[i + 1];
				A[i + 1] = sw;
				bl = 1;
				as++;
			}
			co++;
		}
		right--;
		for (i = right; i > left; i--)
		{
			if (A[i - 1] > A[i])
			{
				sw = A[i];
				A[i] = A[i - 1];
				A[i - 1] = sw;
				bl = 1;
				as++;
			}
			co++;
		}
		left++;
	}
	*assign = as;
	*comp = co;
}

void ItemList()
{
	printf("\nMenu:\n");
	printf("1)Создать массив\n");
	printf("2)Распечатать массив\n");
	printf("3)Сортировка пузырьком\n");
	printf("4)Сортировка вставками\n");
	printf("5)Сортировка слиянием\n");
	printf("6)Сортировка подсчетом\n");
	printf("7)Линейный поиск заданного числа\n");
	printf("8)Бинарный поиск заданного числа\n");
	printf("9)Проверка\n");
	printf("10)Результат сортировки\n");
	printf("0)Выход\n");
}

int randArray(int B[], int n, int *a, int *b)
{
	int i, was_filled;
	was_filled = 0;
	printf("Введите нижнюю границу\n");
	scanf_s("%d", a);
	printf("Введите верхнюю границу\n");
	scanf_s("%d", b);
	if (*a <= *b)
	{
		for (i = 0; i < n; i++)
			B[i] = rand() % (*b+1 - *a) + *a;
		was_filled = 1;
	}
	else printf("Верхняя граница не должна быть меньше нижней\n");
	return was_filled;
}

int Keyboard_input(int B[], int n)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("B[%d]= ", i);
		scanf_s("%d", &B[i]);
	}
	return 1;
}

void Find_Borders(int B[], int n, int *a, int *b)
{
	int l, r, i;
	l = B[0]; r = B[0];
	for (i = 1; i < n; i++)
	{
		if (l > B[i])
			l = B[i];
		if (r < B[i])
			r = B[i];
	}
	*a = l; *b = r+1;
}

void print(int B[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d) %d\n", i, B[i]);
	printf("\n");
}

int Check(int *B, int n)
{
	int f = 1;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (B[i + 1] < B[i])
		{
			f = 0;
			break;
		}
	}
	return f;
}

void SortByInserts(int* A, int n, int *comp, int *assign)
{
	int co = 0;
	int as = 0;
	int i, tmp, z;
	for (i = 1; i < n; i++)
	{
		tmp = A[i]; as++;
		z = i;
		while ((z > 0) && (A[z - 1] > tmp))
		{
			co++;
			A[z] = A[z - 1]; as++;
			z--;
		}
		A[z] = tmp; as++;
	}
	*assign = as;
	*comp = co;
}

void print_results(int comp, int assign)
{
	printf("comparsions = %d\nassigns = %d\n", comp, assign);
}

void main()
{
	int B[15000];
	int Bb[15000];
	int n = 15000;
	int t = 10;
	int comparsions;
	int assignments;
	int indexInput, wasfound, sw;
	int lb = 0, rb = 0;
	setlocale(LC_CTYPE, "Russian");
	printf("start\n");
	srand(1000);
	indexInput = 0;
	while (t > 0)
	{
		ItemList();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			printf("Выбор способа ввода:\n1) Случайная генерация на отрезке\n2) Ввод с клавиатуры\n3) Отмена\n");
			scanf_s("%d", &sw);
			if (sw == 1)
				indexInput = randArray(B, n, &lb, &rb);
			else
				if (sw == 2)
				{
					indexInput = Keyboard_input(B, n);
					Find_Borders(B, n, &lb, &rb);
				}
				else break;
		}
		case 2:
		{
			if (indexInput == 1)
				print(B, n);
			else printf("Массив отсутствует\n");
			break;
		}
		case 3:
		{
			if (indexInput == 1)
			{
				comparsions = 0;
				assignments = 0;
				SortBubble(B, n, &comparsions, &assignments);
				print(B, n);
				print_results(comparsions, assignments);
			}
			else printf("Массив отсутствует\n");
			break;
		}
		case 4:
		{
			if (indexInput == 1)
			{
				SortByInserts(B, n, &comparsions, &assignments);
				print(B, n);
				print_results(comparsions, assignments);
			}
			else printf("Массив отсутствует\n");
			break;
		}
		case 5:
		{
			if (indexInput == 1)
			{
				comparsions = 0; assignments = 0;
				Merge_sort(B, Bb, 0, n-1, &comparsions, &assignments);
				print(B, n);
				print_results(comparsions, assignments);
			}
			else printf("Массив отсутствует\n");
			break;
		}
		case 6:
		{
			if (indexInput == 1)
			{
				Count_sort(B, n, lb, rb, &comparsions, &assignments);
				print(B, n);
				print_results(comparsions, assignments);
			}
			else printf("Массив отсутствует\n");
			break;
		}
		case 7:
		{
			if (indexInput == 1)
			{
				wasfound = Linear_search(B, n);
				if ((wasfound > -1) && (wasfound < n))
					printf("Элемент находится на %d позиции\n", wasfound);
				else printf("Элемент не найден\n");
				break;
			}
			else printf("Массив отсутствует\n");
		}
		case 8:
		{
			if (indexInput == 1)
			{
				if (Check(B, n) == 1)
				{
					wasfound = Binar_search(B, n);
					if (wasfound > -1)
						printf("Элемент находится на %d позиции\n", wasfound);
					else printf("Элемент не найден\n");
				}
				else printf("Массив не отсортирован\n");
				break;
			}
			else printf("Массив отсутствует\n");
		}
		case 9:
		{
			if (indexInput == 1)
			{
				wasfound = Check(B, n);
				if (wasfound == 1)
					printf("Массив отсортирован\n");
				else printf("Массив не отсортирован\n");
			}
			else printf("Массив отсутствует\n");
		}
		case 10:
		{
			if (Check(B, n) == 1)
				print_results(comparsions, assignments);
			else printf("Массив не отсортирован\n");
		}
		}
	}
}