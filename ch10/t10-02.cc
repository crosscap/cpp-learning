#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
	int counter;
	string input;
	list<string> ls;
	std::ifstream input_file("numbers.txt");

	while (input_file >> input) {
		ls.push_back(input);
	}
	cout << "Enter the number you want to count.\n";
	cin >> input;
	counter = count(ls.begin(), ls.end(), input);
	cout << "Have " << counter << " of " << input << " in the vector.\n";

	return 0;
}