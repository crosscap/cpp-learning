#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::count_if;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
	int counter;
	string input;
	list<string> ls;
	std::ifstream input_file("story.txt");

	while (input_file >> input) {
		ls.push_back(input);
	}
	counter = count_if(ls.begin(), ls.end(),
	                   [](string str) { return str.size() >= 6; });
	cout << "Have " << counter << " of words "
		 << "greater than 6 in the vector.\n";

	return 0;
}