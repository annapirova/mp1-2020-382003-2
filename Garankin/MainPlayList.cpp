#include "PlayList.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	PlayList pl;
	pl.Download("list1.txt");
	int n = -1;
	while (n != 0) {
		cout << "Playlist по названию песни 1" << endl;
		cout << "Playlist по году выпуска песни 2" << endl;
		cout << "Playlist по длительности песни 3" << endl;
		cout << "¬ыйти из создани€ playlist нажмите 0" << endl;
		cin >> n;
		if (n == 1) {
			pl.SelectByName("file2.txt");
		}
		if (n == 2) {
			pl.SelectByYear("file2.txt");
		}
		if (n == 3) {
			pl .SelectByTime("file2.txt");
		}
	}
}