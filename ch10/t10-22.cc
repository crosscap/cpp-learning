#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <string>

using std::bind;
using std::cin;
using std::count_if;
using std::cout;
using std::endl;
using std::list;
using std::string;

using namespace std::placeholders;

bool shorterEqualThanNum(const string &str, string::size_type sz);

int main()
{
	int counter;
	string input;
	list<string> ls;
	std::ifstream input_file("story.txt");

	while (input_file >> input)
		ls.push_back(input);
	counter = count_if(ls.begin(), ls.end(), bind(shorterEqualThanNum, _1, 6));
	cout << "Have " << counter << " of "
		 << "words" << " less than 6 in the list.\n";

	return 0;
}

bool shorterEqualThanNum(const string &str, string::size_type sz)
{
	return str.size() <= sz;
}