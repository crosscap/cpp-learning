#include <iostream>
#include <iterator>
#include <vector>

using std::reverse_iterator;
using std::vector;

int main()
{
	vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (vector<int>::reverse_iterator riter = vi.rbegin(), rend = vi.rend();
	     riter != rend; ++riter)
		std::cout << *riter << " ";
	std::cout << std::endl;

	return 0;
}