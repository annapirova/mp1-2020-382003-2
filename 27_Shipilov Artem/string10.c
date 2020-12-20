#include <stdio.h>
#include <locale.h>
#include <windows.h>


void String() 
{
	int n;
	printf("Введите количество символов\n");
	scanf_s("%d ", &n);
	char* string = (char*)malloc(sizeof(char) * n);
	gets_s(string, n);
	string[strlen(string)] = '\0';
	int i = 0;
	int c = 0;
	while (string[i] != '\0') 
	{ 
		if (string[i] == 'А') 
		{ 
			c++; 
			while (string[i] != ' ' && string[i] != '\0') 
			{ 
				i++;
			}
		}
		i++;
		while (string[i] == ' ') 
		{
			i++;
		}
	}
	printf("Количество слов с буквой А = %d\n", c);
	free(string);
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String();
}