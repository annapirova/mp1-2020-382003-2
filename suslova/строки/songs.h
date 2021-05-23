#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Composition
{
public:
	string name, author, year;
public:
	Composition(string _name, string _author, string _year) 
	{
		name = _name;
		author = _author;
		year = _year;
	}
};

class Selection 
{
private:
	vector <Composition> compositions;
	vector <Composition> result;
public:
	void load_from_file(string name_in) 
	{
		string line;
		string name = "", author = "", year = "";

		ifstream ifs;
		ifs.open(name_in);
		while (getline(ifs, line)) 
		{
			int i = 0;
			if (line[i] == '"') 
			{
				name += line[i];
				i++;
				while (line[i] != '"') 
				{
					name += line[i];
					i++;
				}
				name += line[i];
				i++;
			}
			i++;
			while (!isdigit(line[i + 1])) 
			{
				author += line[i];
				i++;
			}
			i++;
			for (; i < line.length(); i++) 
			{
				year += line[i];
			}
			compositions.push_back(Composition(name, author, year));
			name = author = year = "";
		}
		ifs.close();
	}

	void save_to_file(string name_out) 
	{
		string line = "";

		ofstream ofs;
		ofs.open(name_out);
		for (int i = 0; i < result.size(); i++) 
		{
			line += result[i].name + " " + result[i].author + " " + result[i].year;
			ofs << line << "\n";
			line = "";
		}
		ofs.close();
	}

	string lower_case(string value) 
	{
		string result = "";
		for (int i = 0; i < value.length(); i++) 
		{
			result += tolower(value[i]);
		}
		return result;
	}

	void process_request(string request) 
	{
		string value = "";
		int i = 0;
		while (request[i] != '_') 
		{
			value += request[i];
			i++;
		}

		if (value == "all") 
		{
			if (!isdigit(request[i + 1])) 
			{
				string author = "";
				for (int j = i + 1; j < request.length(); j++) 
				{
					author += request[j];
				}

				for (int k = 0; k < compositions.size(); k++) 
				{
					if (lower_case(compositions[k].author).find(author) != -1) 
					{
						result.push_back(compositions[k]);
					}
				}
			}
			else {
				string year = "";
				for (int j = i + 1; j < request.length(); j++) 
				{
					year += request[j];
				}

				for (int k = 0; k < compositions.size(); k++) 
				{
					if (compositions[k].year.find(year) != -1) 
					{
						result.push_back(compositions[k]);
					}
				}
			}
		}
		else if (value == "name") 
		{
			string name = "";
			for (int j = i + 1; j < request.length(); j++) 
			{
				name += request[j];
			}

			for (int k = 0; k < compositions.size(); k++) 
			{
				if (lower_case(compositions[k].name).find(name) != -1) 
				{
					result.push_back(compositions[k]);
				}
			}
		}
		else if (value == "year") 
		{
			string year = "", year1 = "", year2 = "";
			for (int j = i + 1; j < request.length(); j++)
			{
				if (request[j] == '_') 
				{
					year1 = year;
					year = "";
					j++;
				}
				year += request[j];
			}
			year2 = year;

			for (int k = 0; k < compositions.size(); k++) 
			{
				if (compositions[k].year >= year1 && compositions[k].year <= year2) 
				{
					result.push_back(compositions[k]);
				}
			}
		}
		else 
		{
			cout << "Wrong request!\n";
		}
	}
};