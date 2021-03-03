#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct
{
	char name[20];
	double mark1;
	double mark2;
}
typedef Student;

// найти позицию строки substr в строке str
int Find(char* str, char* word)
{
	int start, finish;
	int j = 0;
	int i = 0;
	bool f = false;

	while (i < strlen(str))
	{
		f = true;
		while ((i < strlen(str)) &&
		       (str[i] != word[0])) i++;
			//i - первая буква
		if (i == strlen(str))
		{
			// не нашли
			return -1;
		}
		start = i;
		j = 0;
		while (f && (j < strlen(word)))
		{
			if (word[j] == str[i])
			{
				i++; j++;
			}
			else f = false;
		}
		//i - индекс сразу за словом
		finish = i;
		if ((finish - start == strlen(word)) && f)
		{
			return start; // это ответ
		}
		else
		{
			// это не то слово
			// ищу следующее вхождение первой буквы
			i = start + 1;
		}
	}
	if (!f)
	{
		return -1;
	}
}
// найти позицию строки substr, допускается отличие в k знаках от образца
int FindK(char* str, char* substr, int k) 
{
}


void main()
{
	char* str = "math and programming are cool";
	char* word = "program";
	char* word2 = "progRAM";
	char* word3 = "yellow";
	char* word4 = "mathmath";
	char* word5 = "are";

	int p1, p2, p3, p4, p5;
	p1 = Find(str, word);
	p2 = Find(str, word2);
	p3 = Find(str, word3);
	p4 = Find(str, word4);
	p5 = Find(str, word5);

	printf("%d %d %d %d %d\n", p1, p2, p3, p4, p5);
}

void main200()
{
	char s1[10] = "123.5";
	char s2[20] = "35, c=36";
	char stud[200] = "Ivanov 5.5 4.5";
	char name[20];
	double mark1, mark2;
	double a;
	int b, c;
	char* pos;

	
	a = atof(s1);
	b = atoi(s2);
	pos = strrchr(s2, 'c');
	c = atof(pos + 2);
	printf("a %lf b %d c %d\n", a, b, c);

	sscanf(s2, "%d, c=%d", &b, &c);
	printf("a %lf b %d c %d\n", a, b, c);
	sscanf(stud, "%s %lf %lf", name, &mark1, &mark2);
	printf("name is %s, m1 is %lf, m2 is %lf\n", name, mark1, mark2);  
}

void main100()
{
	char stud[200] = "Ivanov 5.5 4.5";
	char name[20];
	double mark1, mark2;

	// много студентов
	//char names[100][20];
	//double mark1[100];
	//double mark2[100];
	//double marks2[2][100];
	//double marks3[100][2];

	Student s;
	Student* s2;	
	
	strcpy(s.name, "Vasya");
	s.mark1 = 5.5;
	s.mark2 = 4.5;

	s2 = (Student*)malloc(sizeof(Student));
	strcpy(s2->name, "Petya");
	s2->mark1 = 4.0;
	s2->mark2 = 4.5;

	sscanf(stud, "%s %lf %lf", name, &mark1, &mark2);
	printf("name is %s, m1 is %lf, m2 is %lf\n", name, mark1, mark2);
}