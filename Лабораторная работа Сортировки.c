#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "windows.h"

void menu();
void print();
void ArrayInput();
void randArray();
void BubbleSort();
void InsertionSort();
void MergeSort();
void Merge();
void QuickSort();
void ShakerSort();

void main()
{
    int t = 1, n = 0;
    bool wasInput = false;
    printf("Start\n");
    int* A = NULL;
    LARGE_INTEGER start, finish, freq;
    double time;
    QueryPerformanceFrequency(&freq);

    while (t != 0)
    {
        menu();
        scanf_s("%i", &t);
        switch (t)
        {
        case 1:
        {
            printf("Enter the value of the array\n");
            scanf_s("%d", &n);
            A = (int*)malloc(n * sizeof(int));
            if (NULL == A)
            {
                printf("OS didn't gave memory. Exit..");
                exit(1);
            }
            else printf("Array successfully created!");
            ArrayInput(A, n);
            wasInput = true;
            break;
        }
        case 2: {
            printf("Enter the value of the array\n");
            scanf_s("%d", &n);
            A = (int*)malloc(n * sizeof(int));
            if (NULL == A)
            {
                printf("OS didn't gave memory. Exit..");
                exit(1);
            }
            else printf("Array successfully created!");
            randArray(A, n);
            wasInput = true;
            break;
        }
        case 3: {
            if (wasInput)
                print(A, n);
            else printf("Please, Create an array!\n");
            break;
        }
        case 4: {
            if (wasInput)
            {
                QueryPerformanceCounter(&start);
                BubbleSort(A, n);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
                printf("time %lf\n", time);
            }
            else printf("Create an array!");
            break;
        }
        case 5: {
            if (wasInput)
            {
                int nc = 0, nsw = 0;
                QueryPerformanceCounter(&start);
                InsertionSort(A, n, &nc, &nsw);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
                printf("time %lf\n", time);
                printf("Swaps: %d Comparisons: %d\n", nsw, nc);
            }
            else printf("Create an array!");
            break;
        }
        case 6: {
            if (wasInput)
            {
                int nc = 0, nsw = 0;
                QueryPerformanceCounter(&start);
                MergeSort(A, 0, n, &nc, &nsw);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
                printf("time %lf\n", time);
                printf("Swaps: %d Comparisons: %d\n", nsw, nc);
            }
            else printf("Create an array!");
            break;
        }
        case 7: {
            if (wasInput)
            {
                QueryPerformanceCounter(&start);
                QuickSort(A, 0, n - 1);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
                printf("time %lf\n", time);
            }
            else printf("Create an array!");
            break;
        }
        case 8: {
            if (wasInput)
            {
                int nc = 0, nsw = 0;
                QueryPerformanceCounter(&start);
                ShakerSort(A, 0, n-1, &nc, &nsw);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
                printf("time %lf\n", time);
                printf("Swaps: %d Comparisons: %d\n", nsw, nc);
            }
            else printf("Create an array!");
            break;
        }
        }
    }
    free(A);
}

    void menu()
{
    printf("\nMENU:\n");
    printf("1. Create and fill the array yourself\n");
    printf("2. Create and fill the array with random numbers\n");
    printf("3. Output an array\n");
    printf("4. BubbleSort\n");
    printf("5. InsertionSort\n");
    printf("6. MergeSort\n");
    printf("7. QuickSort\n");
    printf("8. ShakerSort\n");
    printf("0. Exit\n");
}

void print(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%i ", A[i]);
    printf("\n");
}

void ArrayInput(int A[], int n)
{
    printf("Start typing a sequence of numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &A[i]);
    }
}

void randArray(int A[], int n)
{
    int i;
    int a, b;
    printf("Enter the minimum and maximum number\n");
    scanf_s("%d %d", &a, &b);
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % (b - a) + a;
    }
}

void BubbleSort(int A[], int n)
{
    int i, j;
    int tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

void InsertionSort(int A[], int n, int* nc, int* nsw)
{
    int i, t, j;
    for (i = 0; i < n; i++)
    {
        t = A[i];
        j = i - 1;
        while ((j >= 0) && (A[j] > t))
        {
            A[j + 1] = A[j];
            j--;
            (*nsw)++;
        }
        A[j + 1] = t;
    }
    
}

void MergeSort(int A[], int left, int right, int* nc, int* nsw)
{
    int mid = (right + left) / 2;
    (*nc)++;
    if ((right - left) < 2)
    {
        return;
    }
    else
    MergeSort(A, left, mid, &(*nc), &(*nsw));
    MergeSort(A, mid, right, &(*nc), &(*nsw));
    Merge(A, left, mid, right, &(*nc), &(*nsw));
}

void Merge(int A[], int left, int mid, int right, int* nc, int* nsw)
{
    int it1 = 0;
    int it2 = 0;
    int* TMP = (int*)malloc((right - left) * sizeof(int));
    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (A[left + it1] < A[mid + it2])
        {
            TMP[it1 + it2] = A[left + it1];
            it1++;
            (*nsw)++;
        }
        else
        {
            TMP[it1 + it2] = A[mid + it2];
            it2++;
            (*nsw)++;
        }
    }
            while (left + it1 < mid)
            {
                TMP[it1 + it2] = A[left + it1];
                it1++;
                (*nsw)++;
            }
            while (mid + it2 < right)
            {
                TMP[it1 + it2] = A[mid + it2];
                it2++;
                (*nsw)++;
            }
            for (int i = 0; i < it1 + it2; i++)
                A[left + i] = TMP[i];
            (*nsw)++;
            free(TMP);
}

void QuickSort(int A[], int left, int right)
{
    int l = left, r = right, tmp = 0;
    int opora = A[(l + r) / 2]; 
    while (l <= r)
    {
        while (A[l] < opora)
        {
            l++;
        }
        while (A[r] > opora) {
            r--;
        }
        if (l <= r)
        {
            tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
            l++;
            r--;
        }
    }
    if (left < r)
        QuickSort(A, left, r);
    if (right > l)
        QuickSort(A, l, right);
}

void ShakerSort(int A[], int left, int right, int* nc, int* nsw)
{
    int tmp = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (A[i] > A[i + 1])
            {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                (*nsw)++;
            }
            (*nc)++;
        }
        right--;
         
        for (int j = right; j > left; j--)
        {
            if (A[j] < A[j - 1])
            {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                (*nsw)++;

            }
            (*nc)++;
        }
        left++;
    }

}
