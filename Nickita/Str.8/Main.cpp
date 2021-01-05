#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void polimorf(char** slovar, int n)
{
	int flag = 1;
	int len1 = 0, len2 = 0;
	for (int i = 0; i < n; i++)
	{
		len1 = strlen(slovar[i]);
		for(int j = i; j < n; j++)
		{
			if(i == j)
			{
				continue;
			}
			flag = 1;
			len2 = strlen(slovar[j]);
			if(len1 == len2)
			{
				for (int l = 0, r = len1 - 1; l <= len1 / 2; l++, r--)
				{
					if (slovar[i][l] != slovar[j][r])
					{
						flag = 0;
						break;
					}
				}
			}
			else
			{
				flag = 0;
			}
			if (flag)
			{
				printf("(%s - %s)", slovar[i], slovar[j]);
			}
		}

	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	const int max_len = 128;
	int n_words;
	char word[max_len];

	printf("¬ведите количество слов в словаре: ");
	scanf("%d", &n_words);
	char** slovar = (char**)malloc(n_words *(sizeof(char*)));
	if (!slovar)
		return 0;
	
	for (int i = 0; i < n_words; i++)
	{
		printf("¬ведите слово\n");
		scanf("%s", &word);
		slovar[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));
		strcpy(slovar[i], word);
	}
	polimorf(slovar, n_words);

	for(int i = 0; i < n_words; i++)
	{
		free(slovar[i]);
	}
	free(slovar);
	
	return 0;
}

