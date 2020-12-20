#include <stdio.h>
#include <locale.h>
#include <windows.h>

void String() 
{
	int n;
	printf("¬ведите количество символов - ");
	scanf_s("%d ", &n);
	char* string = (char*)malloc(sizeof(char) * n);
	gets_s(string, n); // выводит всю строку
	string[strlen(string)] = '\0';
	printf("\n----------------------------------------------------\n");
	int i = 0;
	int count = 0;
	while (string[i] != '\0') 
	{
		if (count == 59) 
		{
			printf("\n");
			count = 0;
		}
		if (string[i] == '$') 
		{
			if (i != 0) printf("\n");
			count = 4;
			i++;
		}
		printf("%c", string[i]);
		count++;
		i++;
	}
	printf("\n");
	free(string);
}

int main() 
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String();
}