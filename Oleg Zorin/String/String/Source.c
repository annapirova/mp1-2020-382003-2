#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "malloc.h"

int CountWordsW(char* str, char* D)
{
	int i, k = 0, len;
	char* p, * p2;
	len = (int)strlen(str);

	for (i = 1; i < len; i++)
	{
		p = strchr(D, str[i]);
		if (p != NULL)
		{
			p2 = strchr(D, str[i - 1]);
			if (p2 == NULL)
				k++;
		}
	}

	if (strchr(D, str[len - 1]) == NULL)
	{
		k++;
	}

	return k;
}


void MallocChar(char*** str, int n)
{
	int i;
	*str = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
	{
		(*str)[i] = (char*)malloc(sizeof(char) * 20);
	}
}

//void FreeChar(char*** str, int n)
//{
//	int i;
//
//	for (i = 0; i < n; i++)
//		free((*str)[i]);
//	free(*str);
//}

bool checkPalindrome(char* str)
{
	int i, j;
	bool flag = true;

	i = 0;
	j = (int)strlen(str) - 1;

	while ((i <= j) && flag)
	{
		if (str[i] != str[j])
			flag = false;
		i++;
		j--;
	}

	return flag;
}

void SaveWords(char** words, char* str, char* D)
{
	int i = 0;
	char* p = NULL;
	char* next = NULL;

	p = strtok_s(str, D, &next);
	while (p != NULL)
	{
		words[i] = p;
		p = strtok_s(NULL, D, &next);
		i++;
	}
}

int CountPalindromes(char** words, int n)
{
	int i, j = 0;
	bool check;

	for (i = 0; i < n; i++)
	{
		check = checkPalindrome(words[i]);
		if (check)
		{
			j++;
		}
	}

	return j;
}

void SavePalindromes(char** pal, char** words, int n)
{
	int i, j = 0;
	bool check;

	for (i = 0; i < n; i++)
	{
		check = checkPalindrome(words[i]);
		if (check)
		{
			pal[j] = words[i];
			j++;
		}
	}
}

void CountRepit(char** words, int* counts, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
				counts[i]++;
		}
	}
}

void main()
{
	char mystr[200]= "Poops, nun, helmet, pizza, helmet, right, left, pizza, nun!";
	char* delim = " ,.?!";
	char** words;
	char** palindromes;
	int* counts;
	int i, n, m;

	//fgets(mystr, 200, stdin);

	n = CountWordsW(mystr, delim);
	MallocChar(&words, n);
	SaveWords(words, mystr, delim);
	m = CountPalindromes(words, n);
	MallocChar(&palindromes, m);
	SavePalindromes(palindromes, words, n);

	//countings repits
	counts = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		counts[i] = 0;
	
	CountRepit(words, counts, n);

	//print:
	printf("Words:\n");
	for (i = 0; i < n; i++)
	{
		printf("%10s\t", words[i]);
		printf("%d\n", counts[i]);
	}
	printf("Palindromes:\n");
	for (i = 0; i < m; i++)
		printf("%10s\n", palindromes[i]);

	//FreeChar(&words, n);
	//FreeChar(&palindromes, m);
	free(counts);
}