#include "PlayList.h"
#include <iostream>
#include <cstdlib>
#include <playlist.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

void PlayList:: Download(string txt)
{
	ifstream f(txt);
	string tmp;
	if (f.is_open())
	{
		while (getline(f, tmp))
		{
			play.push_back(Song(tmp));
		}
	}
	f.close();
}


void PlayList:: SelectByName(string txt) 
{
	string _name;
	cout << "¬ведите название песни" << endl;
	cin >> _name;
	vector<Song>::iterator it = play.begin();
	ofstream of(txt);

	if (of)
	{
		for (it = play.begin(); it != play.end(); it++)
		{
			Song s = *it;
			if (_name == s.name)
				of << s.name << " " << s.year << " " << s.time << "\n";
		}
	}
	of.close();
}

void PlayList:: SelectByYear(string txt) 
{
	int _year;
	cout << "¬ведите год песни" << endl;
	cin >> _year;
	vector<Song>::iterator it = play.begin();
	ofstream of(txt);

	if (of)
	{
		for (it = play.begin(); it != play.end(); it++)
		{
			Song s = *it;
			if (_year == s.year)
				of << s.name << " " << s.year << " " << s.time << "\n";
		}
	}
	of.close();
}

void PlayList:: SelectByTime(string txt) 
{
	double _time;
	cout << "¬ведите продолжительность песни" << endl;
	cin >> _time;
	vector<Song>::iterator it = play.begin();
	ofstream of(txt);

	if (of)
	{
		for (it = play.begin(); it != play.end(); it++)
		{
			Song s = *it;
			if (_time == s.time)
				of << s.name << " " << s.year << " " << s.time << "\n";
		}
	}
	of.close();
}

//void PlayList:: Save(string txt)
//{
	//ofstream of(txt);
//}

Song::Song()
{
	name = "";
	year = 0;
	time = 0;
}

Song::Song(string str)
{
	string tmp;
	stringstream s;
	s << str;
	s >> name >> year >> time;
}