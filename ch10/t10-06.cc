#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::fill_n;
using std::list;

int main()
{
	int input;
	list<int> li;
	std::ifstream input_file("numbers.txt");

	while (input_file >> input) {
		li.push_back(input);
	}
	fill_n(li.begin(), li.size(), 0);
	for (const auto &ri : li)
		cout << ri << ' ';
	cout << endl;

	return 0;
}