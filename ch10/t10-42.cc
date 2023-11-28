#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::list;

void elimDups(list<string> &ls);
void display_ls(const list<string> &ls);

int main()
{
	string input;
	list<string> ls;
	std::ifstream input_file("story.txt");

	while (input_file >> input) {
		ls.push_back(input);
	}
	elimDups(ls);
	display_ls(ls);

	return 0;
}

void elimDups(list<string> &ls)
{
	ls.sort();
	ls.unique();
}

void display_ls(const list<string> &ls)
{
	for (auto &rs : ls) {
		cout << rs << " ";
	}
	cout << endl;
}