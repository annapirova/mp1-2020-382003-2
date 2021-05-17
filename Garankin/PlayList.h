#include <iostream>
#include <cstdlib>
#include <playlist.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#pragma once

using namespace std;


class PlayList 
{
private:
	vector<Song> play;
public:
	void Download(string txt);
	void SelectByName(string txt);
	void SelectByTime(string txt);
	void SelectByYear(string txt);
	//void Save(string txt);
};


class Song
{
public:
	Song();
	Song(string str);
	string name;
	int year;
	double time;
};




