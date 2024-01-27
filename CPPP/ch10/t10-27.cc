#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::back_inserter;
using std::list;
using std::sort;
using std::unique_copy;
using std::vector;

int main()
{
	int input, counter;
	vector<int> vi;
	list<int> li;
	std::ifstream input_file("numbers.txt");

	while (input_file >> input)
		vi.push_back(input);
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), back_inserter(li));
	for (auto &ri : li)
		std::cout << ri << " ";
	std::cout << std::endl;
}