#include <stdio.h>
#include  "math.h"
void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void scan(int b[], int a) {
    int i;
    for (i = 0; i < a; i++)
    {
        scanf_s("%d", &b[i]);
    }
}

void print(int b[], int n) {
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}

void sort1(int b[], int n)
{
    int i = 0, j = 0, a = 0, p = 0;
    a = n - 1; p = 0;
    for (i = 0; i < n - 1; i++) {
        swap(&a, &p); a = (-1) * a;
        for (j = a; j < p; j++)
        {
            if (b[abs(j)] > b[abs(j) + 1]) { swap(&b[abs(j)], &b[abs(j) + 1]); }
        }
        p = abs(p) - 1; a = abs(a) + 1;
    }


}

void sort2(int b[], int n)
{
    int i = 0, j = 0, a = 0, p = 0;
    a = n - 1; p = 0;
    for (i = 0; i < n - 1; i++) {
        swap(&a, &p); a = (-1) * a;
        for (j = a; j < p; j++)
        {
            if (b[abs(j)] < b[abs(j) + 1]) { swap(&b[abs(j)], &b[abs(j) + 1]); }
        }
        p = abs(p) - 1; a = abs(a) + 1;
    }


}

void menu()
{
    printf("\n1. Enter the length of the array\n2. Array input\n3. Sort the array in ascending order\n4. Sorting the array in descending order\n5. Print array\n0. Exit the program\n");
}

int main()
{
    int a = -1, s, i, f = 0, t = 0;
    int b[1000];

    for (i = 0; i < 1000; i++)
    {
        b[i] = 0;
    }

    do {
        menu(); scanf_s("%d", &s); printf("\n");
        switch (s)
        {
        case 1:scanf_s("%d", &a); f = 1; break;
        case 2: if (f == 0) { printf("Warning! Enter the length of the array and try again\n"); break; }
              else { scan(b, a); t = 1; break; }
        case 3:if (t == 0) { printf("Warning! Enter an array and try again\n"); }
              else { sort1(b, a); } break;
        case 4:if (t == 0) { printf("Warning! Enter an array and try again\n"); }
              else { sort2(b, a); } break;
        case 5:if (t == 0) { printf("Warning! Enter an array and try again\n"); }
              else { print(b, a); } break;
        case 0:; break;
        }




    } while (a != 0);



}
