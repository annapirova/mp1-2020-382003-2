#include <stdio.h>
#include "locale.h"

void carray(int a[][10], int n, int m)
{ 
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        a[i][j] = rand() % 1000;
    }
}

void trans(int a[][10], int n, int m)
{
    int i, j, tmp;
    for( int i = 0; i < n; i++)
    {
      for ( j = i+1; j < m; j++ ) 
        {
           tmp = a[i][j];
           a[i][j] = a[j][i];
           a[j][i] = tmp;
        }
    }
}

void print(int a[][10], int n, int m)
{
   for(int i = 0; i < n; i++)  
   {
     for(int j = 0; j < m; j++) 
       {
         printf("%d \t", a[i][j]);
       }
     printf("\n"); 
   } 

}

void menu()
{
    printf("1. создать массив \n");
    printf("2. транспортировать матрицу \n");
    printf("3. вывести массив \n");
}

void main()
{
    setlocale(LC_ALL, "rus");
    int t = 1, n, m, a[10][10], tmp;
    srand(12223);
    
    while ((t == 1) || (t == 2) || (t == 3))
    {
    
    menu();
    scanf("%d", &t);
    switch(t)
    {
        case 1:
            n = 1 + rand() % 9;
            m = 1 + rand() % 9;
            carray(a, n, m);
            break;
        case 2:
            trans(a, n, m);
            tmp = n;
            n = m;
            m = tmp;
            break;
        case 3:
            print(a, n, m);
            break;
        default:
            break;
    }
    }
    
}