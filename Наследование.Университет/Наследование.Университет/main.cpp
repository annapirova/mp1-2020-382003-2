#include <clocale>
#include <iostream>
#include "Professor.h"
#include "Student.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int a=0;
	int n=0, i;
	int cur_group;
	Student* MyGroup;
	MyGroup = new Student[n];
	Professor pr;
	while (a != 5)
	{
		cout << "1. �������� ������ ���������\n2. �������� �������������\n3. ������ ���������\n4. ���������� �������������\n5. �����\n";
		cin >> a;

		if (a == 2)
		{
			pr.input_name();
			pr.input_age();
			pr.input_subject();
		}
		if (a == 1)
		{
			cout << "������� ���������� ���������\n";
			cin >> n;
			MyGroup = new Student[n];
			cout << "������� ����� ������\n";
			cin >> cur_group;
			for (i = 0; i < n; i++)
			{
				MyGroup[i].group = cur_group;
			}
			for (i = 0; i < n; i++)
			{
				cout << "student �" << i << endl;
				MyGroup[i].input_name();
				MyGroup[i].input_age();
			}
		}
		if (a == 3)
			if (n > 0)
			{
				{
					for (i = 0; i < n; i++)
					{
						cout << MyGroup[i].group << "   " << MyGroup[i].name << "   " << MyGroup[i].age << "\n";
					}
				}
			}
			else cout << "������ �� ������\n";
		if (a == 4)
			cout << pr.subject << "  " << pr.name << "  " << pr.age << "\n";
	}
	return 0;
}
