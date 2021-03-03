#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void PrintText(char** words, int n)
{
	int i;
	printf("***\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", words[i]);
	}
	printf("***\n");
}

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
	// " program 1, program 22"
	prev = str; // предыдущий разделитель
	j = 0;
	for (i = 0; i < len; i++)
	{
		// str[i] входит ли в подмножество символов D 
		p = strchr(D, str[i]); // указатель на символ в D
		p2 = str + i; // // указатель на символ в str
		if (p != NULL) // разделитель
		{
			if (p2 - prev > 1)
			{
				strncpy(words[j], prev + 1, p2 - prev - 1);
				words[j][p2 - prev - 1] = '\0';
				j++;
			}
			prev = p2;
		}
	}
	if (prev < str + len - 1)
	{
		p2 = str + len;
		strncpy(words[j], prev + 1, p2 - prev - 1);
		words[j][p2 - prev - 1] = '\0';
	}

}

void main2()
{
	char* mystr = "I like programming and math";
	char mystr2[200];
	char test[200];
	char* p, * pnext;
	int k;
	int pos;

	char t = '\0';

	//печать
	printf("s1 %s\n", mystr);

	//считывать - 0
	scanf("%s", mystr2); // до пробела
	printf("%s\n", mystr2);

	//считывать - 1
	scanf("%[^\n]%*c", mystr2);
	printf("%s\n", mystr2);

	//считывать - 2
	fgets(mystr2, 200, stdin);
	printf("%s\n", mystr2);

	// примеры вызовов
	k = strlen(mystr);
	strcpy(mystr2, "I like math");
	strcpy_s(mystr2, 200, "I like math");
	strcat_s(mystr2, 200, mystr);
	strncpy_s(test, 200, mystr2, 6);
	printf("%s\n", test);
	// скопировать math
	strncpy_s(test, 200, mystr2 + 7, 4);
	test[5] = '\0';
	printf("%s\n", test);
	//поиск символа
	p = strchr(mystr2, 'm');
	// скопировать math - 2
	strncpy(test, p, 4);
	printf("%s\n", test);
	//поиск строки в строке
	p = strstr(mystr, "math");
	strncpy(test, p, 4);
	printf("%s\n", test);
	// копируем подстроку с 'm' до конца строки
	p = strchr(mystr, 'm');
	strcpy(test, p);
	printf("%s\n", test);

	// поиск
	p = strstr(mystr, "programs");
	pnext = strstr(mystr, "program");
	if (pnext != NULL)
	{
		pos = pnext - mystr;
		printf("pos %d\n", pos);
	}
	else
		printf("not found\n");

	// сравнение
	printf("sompare %s :: %s\n", mystr, mystr2);
	k = strcmp(mystr, mystr2);
	if (k > 0)
		printf("str1 > str2\n");
	else if (k < 0)
		printf("str1 < str2\n");
	else
		printf("str1 == str2\n");
}


void main5()
{
	char* mystr = " program 1, program 22";
	char* mystr2 = " I J";
	char* mystr3 = "...";
	int k1, k2, k3;
	char** words;
	int i;
	char r[20];

	strcpy(r, "12345");
	//Perevorot(mystr, mystr2);
	//printf("%s\n", mystr2);
	//k1 = CountDigits1(mystr);
	//k2 = CountDigits2(mystr);
	//printf("k1 %d k2 %d\n", k1, k2);

	k1 = CountWordsW(mystr2);
	//k2 = CountWordsW(mystr2);
	//k3 = CountWordsW(mystr3);
	//printf("%d %d %d\n", k1, k2, k3);
	words = (char**)malloc(sizeof(char*) * k1);
	for (i = 0; i < k1; i++)
		words[i] = (char*)malloc(sizeof(char) * 20);

	SaveWordsW(mystr2, words);
	PrintText(words, k1);

	for (i = 0; i < k1; i++)
		free(words[i]);
	free(words);
}

