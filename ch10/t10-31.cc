#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::unique_copy;
using std::vector;

int main()
{
	istream_iterator<int> int_iter(std::cin), eof;
	ostream_iterator<int> out_iter(std::cout, " ");
	vector<int> vi;

	while (int_iter != eof)
		vi.push_back(*int_iter++);
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), out_iter);
	std::cout << std::endl;

	return 0;
}