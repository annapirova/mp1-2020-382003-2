#include "math.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
#include "memory.h"
#include "windows.h"
int Menu()
{
	printf("\nMenu: \n");
	printf(" 1. Enter massive \n");
	printf(" 2. Random massive \n");
	printf(" 3. Print massive \n");
	printf(" 4. BubbleSort \n");
	printf(" 5. DvunapBubbleSort \n");
	printf(" 6. InsertSort \n");
	printf(" 7. MergeSort \n");
	printf(" 8. CountSort \n");
	printf(" 9. QuickSort \n");
	printf(" 10. LineSearch \n");
	printf(" 11. BinarSearch \n");	
	printf(" 0. Exit \n");
}

int Vvod(int n, int *B)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &B[i]);
	}
}

int InputRandArray(int *B, int n)
{
	int i;
	int p = n / 2;
	int q = -n / 2;
	for (i = 0; i < n; i++)
	{
		B[i] = rand() % (p - q) + q;
	}
}

int PrintArray(int *B, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");
}
int BubbleSort(int *B, int n, int* nc, int* nsw)
{
	int i, tmp, j;
	bool k = true;
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		k = false;
		(*nc)++;
		for (j = 0; j < n - i - 1; j++)
		{
			(*nc)++;
			if (B[j] > B[j + 1])
			{
				tmp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = tmp;
				(*nsw)++;
				k = true;
			}
		}
	}
}

int InsertSort(int *B, int n, int *nc, int *nsw)
{
	int i, j, tmp;
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		tmp = B[i];
		j = i - 1;
		(*nc)++;
		while (j >= 0 && B[j] > tmp)
		{
			B[j + 1] = B[j];
			j--;
			(*nc)++;
			(*nsw)++;
		}
		B[j + 1] = tmp;
		(*nsw)++;
	}
}

int BubbleSort1(int* B, int n, int *nc, int *nsw)
{
	int i, tmp, j;
	int max = n - 1;
	int min = 0;
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		(*nc)++;
		for (j = min; j < max; j++)
		{
			(*nc)++;
			if (B[j] > B[j + 1])
			{
				tmp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = tmp;
				(*nsw)++;
			}
		}
		tmp = 0;
		for (j = max; j > min; j--)
		{
			(*nc)++;
			if (B[j] < B[j - 1])
			{
				tmp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = tmp;
				(*nsw)++;
			}
		}
	}
} 

int Merge(int* B, int l, int r, int *nc, int *nsw)
{

	if (l == r)
		return;

	int mid = (l + r) / 2;
	Merge(B, l, mid, nc, nsw);
	Merge(B, mid + 1, r, nc, nsw);
	int i = l;
	int j = mid + 1;
	int s = 0;
	int* k = (int*)malloc(sizeof(int) * r);
	(*nc)++;
	for (s = 0; s < r - l + 1; s++)
	{
		(*nc)++;
		if ((r > j) || ((i <= mid) && (B[i] < B[j])))
		{
			k[s] = B[i];
			i++;
			(*nsw)++;
		}
		else
		{
			k[s] = B[j];
			j++;
			(*nsw)++;
		}
		free(k);
	}
	(*nc)++;
	for (s = 0; s < r - l + 1; s++)
	{
		B[l + s] = k[s];
		(*nsw)++;
	}
}
	

int Quick(int* B, int l, int r, int *nc, int *nsw)
{
	int a = B[(r + l) / 2];
	int t;
	int i = l; int j = r;
	(*nc)++;
	while (B[i] < a)
	{
		i++;
		(*nc)++;
	}
	while (B[j] > a)
	{
		j--;
		(*nc)++;
	}
	if (i <= j)
	{
		(*nc)++;
		if (i < j)
		{
			t = B[i];
			B[i] = B[j];
			B[j] = t;
			(*nsw)++;
		}
		i++;
		j--;
		(*nc)++;
	}
	while (i <= j)
	{
		(*nc)++;
		if (i < r)
		{
			Quick(B, i, r, nc, nsw);
		}
		(*nc)++;
		if (j > l)
		{
			Quick(B, l, j, nc, nsw);
		}
	}
}

int countsort(int* B, int n, int *nc, int *nsw)
{
	int* k = (int*)malloc(n * sizeof(int));
	(*nc)++;
	for  (int i = 0; i < n; i++)
	{
		int s = 0;
		(*nc)++;
		for (int j = 0; j < n; j++)
		{
			if (B[j] < B[i])
			{
				s++;
				(*nc)++;
				(*nsw)++;
			}
		}
		k[s] = B[i];
		(*nc)++;
	}
	free(k);
}

int line(int *B, int n, int key, int *nc)
{
	(*nc)++;
	for (int i = 0; i < n; i++)
	{
		(*nc)++;
		if (B[i] == key)
		{
			return i;
		}
		return -1;
		(*nc)++;
	}
}

int binar(int* B, int l, int r, int key, int *nc)
{
	int mid = 0;
	int s = -1;
	(*nc)++;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (key == B[mid] );
		{
			s = mid;
			break;
		}
		if (key < B[mid])
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
		(*nc)++;
	}
	if (s == -1)
		printf("Element not found");
}
int main()
{
	int* A = NULL;
	int* K = NULL;
	int n = 10;
	int t = 10;
	int nSwaps[6];
	int nComp[6];
	srand(1000);
	double alltime[6];
	bool check = false;
	bool check2 = false;
	double time;
	int key;
	LARGE_INTEGER start, finish, st;
	QueryPerformanceCounter(&st);
	do
	{
		Menu();
			scanf_s("%d", &t);
			switch (t)
			{
				case 1:
					if (check2)
					Vvod(A, n);
					check = true;
					break;

				case 2:
					if (check2)
					InputRandArray(A, n);
					check = true;
					break;
				
				case 3:
				
					if (check)
					{
						PrintArray(A, n);
					}
					else
					{
						printf("Input Massive\n");
					}
					break;
				
			case 4:
			
				if (check)
				{
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					BubbleSort(K, n, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[0] = nsw;
					nComp[0] = nc;
					alltime[0] = time;
					BubbleSort(A, n, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			
			case 5:

				if (check)
				{
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					BubbleSort1(K, n, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[1] = nsw;
					nComp[1] = nc;
					alltime[1] = time;
					BubbleSort1(A, n, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;


			case 6:
			
				if (check)
				{
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					InsertSort(K, n, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[2] = nsw;
					nComp[2] = nc;
					alltime[2] = time;
					InsertSort(A, n, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			
			case 7:
			
				if (check)
				{
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					Merge(K, 0, n - 1, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[3] = nsw;
					nComp[3] = nc;
					alltime[3] = time;
					Merge(A, 0, n - 1, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			case 8:
				if (check)
				{
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					countsort(K, n, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[4] = nsw;
					nComp[4] = nc;
					alltime[4] = time;
					countsort(A, n, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			case 9:
			
				if (check)
				{
					memcpy(K, A, sizeof(int)* n);
					int nc = 0;
					int nsw = 0;
					QueryPerformanceCounter(&start);
					Quick(K, 0, n - 1, &nc, &nsw);
					QueryPerformanceCounter(&finish);
					time = (double)(finish.QuadPart - start.QuadPart) / (double)st.QuadPart;
					nSwaps[5] = nsw;
					nComp[5] = nc;
					alltime[5] = time;
					Quick(A, 0, n - 1, &nc, &nsw);
					PrintArray(A, n);
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			case 10:
				
				if (check)
				{
					int nc = 0;
					printf("Enter key\n");
					scanf_s("%d", &key);
					line(A, n, key , &nc);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			case 11:
				if (check)
				{
					int nc = 0;
					printf("Enter key\n");
					scanf_s("%d", &key);
					binar(A, 0, n - 1, key, &nc);
				}
				else
				{
					printf("Input Massive\n");
				}	
			default:
				printf("Please, enter number 1 to 12");
				break;
			}
			
	} while (t != 0);
}