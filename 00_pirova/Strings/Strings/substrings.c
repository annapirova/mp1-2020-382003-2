#include "string.h"
#include "stdio.h"
#include "stdlib.h"

struct
{
	char name[20];
	double mark1;
	double mark2;
}
typedef Student;

int Find(char* str, char* substr) // найти позицию строки substr в строке str
{
}

// найти позицию строки substr, допускается отличие в k знаках от образца
int FindK(char* str, char* substr, int k) 
{
}


void main33()
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

void main()
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