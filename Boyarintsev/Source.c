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
	printf(" 2. Print massive \n");
	printf(" 3. BubbleSort \n");
	printf(" 4. DvunapBubbleSort \n");
	printf(" 5. InsertSort \n");
	printf(" 6. MergeSort \n");
	printf(" 7. CountSort \n");
	printf(" 8. QuickSort \n");
	printf(" 9. LineSearch \n");
	printf(" 10. BinarSearch \n");	
	printf(" 0. Exit \n");
}

int Vvod(int* B, int n)
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
	int p = n;
	int q = -n;
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
	for (i = 1; i < n; i++)
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

int Merge(int* B, int mid, int l, int r, int *nc, int *nsw)
{
	int i = l;
	int j = mid + 1;
	int s = 0;
	int g = r - l + 1;
	int* k;
	k = (int*)malloc(sizeof(int) * g);
	while(i <= mid && j <= r)
	{
		if (B[i] < B[j])
		{
			k[s] = B[i];
			s++;
			i++;
			(*nsw)++;
		}
		else
		{
			k[s] = B[j];
			s++;
			j++;
			(*nsw)++;
		}
	}
	(*nc)++;
	while(i <= mid)
	{
		k[s] = B[i];
		s++;
		i++;
		(*nsw)++;
	}
	while (j <= r)
	{
		k[s] = B[j];
		s++;
		j++;
		(*nsw)++;
	}
	for (s = 0; s < g; s++)
	{
		B[l + s] = k[s];
	}
	free(k);
}
int Merge1(int* B, int l, int r, int *nc, int *nsw)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		Merge1(B, l, mid, &(*nc), &(*nsw));
		Merge1(B, mid + 1, r, &(*nc), &(*nsw));
		Merge(B, mid, l, r, &(*nc), &(*nsw));
	}
	(*nc)++;
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
			t = B[i];
			B[i] = B[j];
			B[j] = t;
			(*nsw)++;
		i++;
		j--;
		(*nc)++;
	}
		(*nc)++;
		if (i < r)
		{
			Quick(B, i, r, &(*nc), &(*nsw));
		}
		(*nc)++;
		if (j > l)
		{
			Quick(B, l, j, &(*nc), &(*nsw));
		}
}

int countsort(int* B, int n, int *nc, int *nsw)
{
	int i, j;
	int s = 0;
	int min, max;
	min = 0;
	max = 0;
	for (i = 0; i < n; i++)
	{
		max = (B[i] > max) ? B[i] : max;
		min = (B[i] < min) ? B[i] : min;
	}
	int* k;
	k = (int*)malloc(sizeof(int) * (max - min + 1));
	k[max - min + 1];
	(*nc)++;
	for (i = 0; i < max - min + 1; i++)
	{
		k[i] = 0;
		(*nc)++;
		(*nsw)++;
	}
	(*nc)++;
	for (i = 0; i < n; i++)
	{
		k[B[i] - min]++;
		(*nc)++;
	}
	printf("\n");
	(*nc)++;
	for (i = 0; i < max - min + 1; i++)
	{
		(*nc) += 2;
		for (j = 0; j < k[i]; j++)
		{
			B[s] = i + min;
			s++;
			(*nc)++;
			(*nsw)++;
		}
	}
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

bool check(int* B, int n)
{
	int i;
	bool f = true;
	for (i = 0; i < n - 1; i++)
	{
		if (B[i + 1] < B[i])
		{
			f = false;
			break;
		}
	}
	return f;
}


int main()
{
	int* A = NULL;
	int* K = NULL;
	int* S = NULL;
	int n = 0;
	int t = 11;
	int k = 2;
	int m, g, gg;
	int nSwaps[6];
	int nComp[10];
	double alltime[6];
	bool ck = false;
	bool ck2 = true;
	int key;
	clock_t time;
	Menu();
	do
	{
			srand(1000);
			scanf_s("%d", &t);
			switch (t)
			{
				case 1:
					do
					{
						printf("Enter size of massive ");
						scanf_s("%d", &n);
					} while (n < 0);
					A = (int*)malloc(sizeof(int) * n);
					do
					{
						printf("1. User Massive\n");
						printf("2. Random Massive\n");
						scanf_s("%d", &k);
					} while (k < 1 || k > 2);

					switch (k)
					{
					case 1: 
						Vvod(A, n);
						break;
					case 2:
						InputRandArray(A, n);
						break;
					}
					S = (int*)malloc(sizeof(int) * n);
					ck2 = true;
					ck = true;
					break;
				
				case 2:
				
					if (ck)
					{
						do
						{
							printf("1. Default\n");
							printf("2. Sort\n");
							scanf_s("%d", &m);
						} while (m < 1 || m > 2);
						if (m == 1)
							PrintArray(A, n);
						else if (!ck2)
							PrintArray(S, n);
						else
							printf("Sort Massive\n");
					}
					else
						printf("Input Massive\n");
					break;
				
			case 3:
			
				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					BubbleSort(K, n, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[0] = nsw;
					nComp[0] = nc;
					alltime[0] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			
			case 4:

				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					BubbleSort1(K, n, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[1] = nsw;
					nComp[1] = nc;
					alltime[1] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;


			case 5:
			
				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					InsertSort(K, n, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[2] = nsw;
					nComp[2] = nc;
					alltime[2] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			
			case 6:
			
				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					Merge1(K, 0, n - 1, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[3] = nsw;
					nComp[3] = nc;
					alltime[3] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;

			case 7:
				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					countsort(K, n, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[4] = nsw;
					nComp[4] = nc;
					alltime[4] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;

			case 8:
			
				if (ck)
				{
					K = (int*)malloc(sizeof(int) * n);
					memcpy(K, A, sizeof(int) * n);
					int nc = 0;
					int nsw = 0;
					time = clock();
					Quick(K, 0, n - 1, &nc, &nsw);
					time = clock() - time;
					if (check(K, n))
					{
						printf("Correct");
					}
					if (ck2)
					{
						memcpy(S, K, sizeof(int) * n);
						ck2 = false;
					}
					printf("Time %f	seconds\n", (double)time / CLOCKS_PER_SEC);
					printf("Swaps %d , compare %d \n", nsw, nc);
					nSwaps[5] = nsw;
					nComp[5] = nc;
					alltime[5] = time;
					free(K);
				}
				else
				{
					printf("Input Massive\n");
				}
				break;

			case 9:
				
				if (ck)
				{
					int nc = 0;
					do
					{
						printf("1. Default\n");
						printf("2. Sort\n");
						scanf_s("%d", &g);
					} while (g < 1 || g > 2);
					printf("Enter key\n");
					scanf_s("%d", &key);
					if (g == 1)
						gg = line(A, n, key, &nc);
					else 
						if (!ck2)
						gg = line(S, n, key, &nc);
						else 
						{
							gg = -1;
							printf("Sort massive\n");
						}
					if (gg == -1)
					{
						printf("Not Found!\n");
					}
					else
					{
						printf("Number %d\n", gg);
					}
					printf("Compare %d\n", nc);
						nComp[6] = nc;
				}
				else
				{
					printf("Input Massive\n");
				}
				break;
			case 10:
				if (ck && !ck2)
				{
					int nc = 0;
					printf("Enter key\n");
					scanf_s("%d", &key);
					gg = binar(A, 0, n - 1, key, &nc);
					if (gg == -1)
					{
						printf("Not Found!\n");
					}
					else
					{
						printf("Number %d\n", gg);
					}
					printf("Compare %d\n", nc);
					nComp[7] = nc;
				}
				else
				{
					printf("Input Massive\n");
				}	
			default:
				printf("Please, enter number 1 to 10");
				break;
			}
			
	} while (t != 0);
	free(A);
}