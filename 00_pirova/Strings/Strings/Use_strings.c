#include "string.h"
#include "stdio.h"

void Perevorot(char* str, char* str2)
{
	int i, len;
	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		str2[len - 1 - i] = str[i];
	}
	str2[len] = '\0';
}

int CountDigits1(char* str)
{
	int i, k = 0, len;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		//'0' <= str[i] <= '9'
		if ((str[i] <= '9') && ('0' <= str[i]))
			k++;
	}
	return k;
}

int CountDigits2(char* str)
{
	int i, k = 0, len;
	char* D = "0123456789";
	char* p;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]);
		if (p != NULL) // str[i] - цифра
			k++;
	}
	return k;
}

int CountDelims(char* str)
{
	int i, k = 0, len;
	char* D = " ,.!?:;";
	char* p;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]);
		if (p != NULL)
			k++;
	}
	return k;
}

int CountWordsW(char* str)
{
	int i, k = 0, len;
	char* D = " ,.!?:;";
	char* p, *p2;
	len = strlen(str);

	for (i = 1; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]);
		if (p != NULL) // разделитель
		{
			p2 = strchr(D, str[i - 1]);
			if (p2 == NULL) // не разделитель
				k++;
		}
	}

	if (strchr(D, str[len - 1]) == NULL)
	{
		k++;
	}

	return k;
}

void SaveWordsW(char* str, char** words)
{
	int i, k = 0, len, j;
	char* D = " ,.!?:;";
	char* p, *p2, *prev;
	len = strlen(str);

	prev = str; // предыдущий разделитель
	j = 0;
	for (i = 1; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]); // указатель на символ в D
		p2 = str + i; // // указатель на символ в str
		if (p != NULL) // разделитель
			if	(p2 - prev > 1)
			{
				strncpy(words[j], prev + 1, p2 - prev - 1);
				words[j][p2 - prev - 1] = '\0';
				j++;
				prev = p2;
			}
	}

}


void main()
{
	char* mystr = " program 1, program 22";
	char* mystr2 = " I J ";
	char* mystr3 = "...";
	int k1, k2, k3;
	char** words;
	int i;

	//Perevorot(mystr, mystr2);
	//printf("%s\n", mystr2);
	//k1 = CountDigits1(mystr);
	//k2 = CountDigits2(mystr);
	//printf("k1 %d k2 %d\n", k1, k2);

	k1 = CountWordsW(mystr);
	//k2 = CountWordsW(mystr2);
	//k3 = CountWordsW(mystr3);
	//printf("%d %d %d\n", k1, k2, k3);
	words = (char**)malloc(sizeof(char*) * k1);
	for (i = 0; i < k1; i++)
		words[i] = (char*)malloc(sizeof(char) * 20);

	SaveWordsW(mystr, words);
	PrintText(words, k1);

	for (i = 0; i < k1; i++)
		free(words[i]);
	free(words);
}

