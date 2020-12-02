#include <stdio.h>
#include "math.h"
#include "locale.h"
#include "stdlib.h"
#include "memory.h"
#include <windows.h>

void menu()
{
    printf("\n1. Ввести массив\n2. Сортировать массив\n3. Печать изначального массива \n4. Сравнение сортировок \n0. Выйти из программы\n Ввод: ");
}

void swap(int* a, int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void print(int* M, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%d ", *(M + i));
    }
    printf("\n");
}

void bubble(int** M, int length, int* compare, int* alter)
{
    int i = 0, j = 0, finish, start;
    start = length - 1; finish = 0;

    for (i = 0; i < length - 1; i++) {
        swap(&start, &finish); *alter = *alter + 1;
        start = (-1) * start;
        for (j = start; j < finish; j++)
        {
            *compare = *compare + 1;
            if (M[abs(j)] > M[abs(j) + 1]) {
                swap(&M[abs(j)], &M[abs(j) + 1]); *alter = *alter + 1;
            }
        }
        finish = abs(finish) - 1; start = abs(start) + 1;
    }

}

void inserts(int** M, int length, int* compare, int* alter)
{
    int i, j = 0, cell = 0;
    for (i = 1; i < length; i++)
    {
        j = i - 1; cell = M[i];

        while ((M[j] > cell) && (j >= 0))
        {
            *compare = *compare + 2;
            M[j + 1] = M[j];
            j = j - 1;

        }

        M[j + 1] = cell; *alter = *alter + 1;

    }

}

void shell(int** M, int length, int* compare, int* alter)
{
    int i, j = 0, cell = 0, step;

    for (step = length / 2; step > 0; step = step / 2)
    {
        for (i = step; i < length; i++)
        {
            j = i - 1; cell = M[i];

            while ((M[j] > cell) && (j >= 0))
            {
                *compare = *compare + 2;
                M[j + 1] = M[j];
                j = j - 1;

            }

            M[j + 1] = cell; *alter = *alter + 1;

        }
    }


}

void unity(int** M, int first, int last, int* compare, int* alter)
{
    int middle, start, final, j, a;
    int* m;
    middle = (first + last) / 2;
    a = (first + last) * 2;
    m = (int*)malloc(a * sizeof(int));

    middle = (first + last) / 2;
    start = first;
    final = middle + 1;

    for (j = first - 1; j < last; j++)
    {
        *compare = *compare + 3;
        if ((start <= middle) && ((final > last) || (M[start - 1] < M[final - 1])))
        {
            m[j] = M[start - 1]; start++;
        }
        else
        {
            m[j] = M[final - 1]; final++;
        }

    }

    for (j = first - 1; j < last; j++)
    {
        M[j] = m[j]; *alter = *alter + 1;
    }

    free(m);
}

void merger(int** M, int first, int last, int* compare, int* alter)
{
    *compare = *compare + 1;
    if (first < last) {
        merger(M, first, (first + last) / 2, compare, alter);
        merger(M, (first + last) / 2 + 1, last, compare, alter);
        unity(M, first, last, compare, alter);
    }
}

void quickly(int** M, int length, int* compare, int* alter)
{
    int middle, j, i;
    j = length - 1;
    i = 0;
    middle = M[length / 2];

    do
    {
        *compare = *compare + 1;
        while (M[i] < middle)
        {
            i++; *compare = *compare + 1;
        }


        while (M[j] > middle)
        {
            j--; *compare = *compare + 1;
        }

        *compare = *compare + 1;
        if (i <= j)
        {
            swap(&M[i], &M[j]); *alter = *alter + 1;
            i++;
            j--;

        }
    } while (i <= j);

    *compare = *compare + 2;
    if (j > 0) { quickly(M, j + 1, compare, alter); }
    if (i < length) { quickly(&M[i], length - i, compare, alter); }
}

int main()
{
    long clock;
    int length = -1, entry = -1, counter = 0, inlet, compare, alter, key, i, a, b, o = 0, j;
    int* M1 = o;
    int* M2 = o;
    int  R[5][3] = { 0 };

    LARGE_INTEGER freq, start, finish;

    QueryPerformanceFrequency(&freq);
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    while (entry != 0) {
        menu(); scanf_s("%d", &entry); printf("\n");
        switch (entry)
        {
        case 1:
            printf("1. Ввести массив вручную\n2. Заполнить массив случайными числами\n Ввод: ");
            scanf_s("%d", &inlet);
            do {
                printf("\nВведите длину массива\n Ввод: ");
                scanf_s("%d", &length); if (length < 1) { printf("\nERROR: Указана некоректная длина\n"); }
            } while (length < 1);
            if (counter != 0) {
                free(M1); free(M2); for (i = 0; i < 5; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        R[i][j] = 0;
                    }
                }
            }
            M1 = (int*)malloc(length * sizeof(int));
            M2 = (int*)malloc(length * sizeof(int));
            switch (inlet)
            {
            case 1: printf("\n Введите массив\n Ввод: ");
                for (i = 0; i < length; i++)
                {
                    scanf_s("%d", &M1[i]);
                }
                break;
            case 2: printf("Введите диапозон массива\n Ввод: ");
                scanf_s("%d%d", &a, &b);
                for (i = 0; i < length; i++)
                {
                    M1[i] = a + rand() % (b - a + 1);
                }
                break;
            }
            counter = 1;  break;
        case 2:if (counter == 0) { printf("ERROR: Введите массив и попробуйте снова\n"); }
              else {
            compare = 0; alter = 0;
            for (i = 0; i < length; i++)
            {
                M2[i] = M1[i];
            }
            printf("1.Cортировка пузырьком \n2.Сортировка вставкой\n3.Сортировка Шелла\n4.Сортировка слиянием\n5.Быстрая сортировка\n Ввод: ");
            scanf_s("%d", &inlet); printf("\nМассив до сортировки: "); print(M2, length);
            switch (inlet) {
            case 1:QueryPerformanceCounter(&start);
                bubble(M2, length, &compare, &alter); key = 0;
                QueryPerformanceCounter(&finish);
                clock = (double)(finish.QuadPart - start.QuadPart);
                break;
            case 2:QueryPerformanceCounter(&start);
                inserts(M2, length, &compare, &alter); key = 1;
                clock = GetTickCount64() - clock;
                break;
            case 3:QueryPerformanceCounter(&start);
                shell(M2, length, &compare, &alter); key = 2;
                QueryPerformanceCounter(&finish);
                clock = (double)(finish.QuadPart - start.QuadPart);
                break;
            case 4:QueryPerformanceCounter(&start);
                merger(M2, 1, length, &compare, &alter); key = 3;
                QueryPerformanceCounter(&finish);
                clock = (double)(finish.QuadPart - start.QuadPart);
                break;
            case 5:QueryPerformanceCounter(&start);
                quickly(M2, length, &compare, &alter); key = 4;
                QueryPerformanceCounter(&finish);
                clock = (double)(finish.QuadPart - start.QuadPart);
                break;
            }
            printf("\nМассив после сортировки: ");
            print(M2, length);
            R[key][0] = compare;
            R[key][1] = alter;
            R[key][2] = (int)clock;
        } break;
        case 3:if (counter == 0) { printf("ERROR: Введите массив и попробуйте снова\n"); }
              else {
            print(M1, length);
        } break;
        case 4: for (i = 0; i < 5; i++)
        {
            switch (i) {
            case 0: printf("\nСортировка пузырьком\n");
                break;
            case 1: printf("\nСортировка вставками\n");
                break;
            case 2: printf("\nСортировка Шелла\n");
                break;
            case 3: printf("\nСортировка слиянием\n");
                break;
            case 4: printf("\nБыстрая сортировка:\n");
                break;
            }
            printf("1) Количество сравнений: %d\n", R[i][0]);
            printf("2) Количество перестановок: %d\n", R[i][1]);
            printf("3) Время сортировки: %d\n", R[i][2]);
        }

              break;
        }
    }


}
