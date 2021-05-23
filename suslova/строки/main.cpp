#include <iostream>
#include "songs.h"
using namespace std;

int main() 
{
	string request;
	cin >> request;

	Selection test;
	test.load_from_file("input.txt");
	test.process_request(request);
	test.save_to_file("output.txt");

	return 0;
}