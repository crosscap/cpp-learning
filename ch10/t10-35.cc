#include <iostream>
#include <iterator>
#include <vector>

using std::reverse_iterator;
using std::vector;

int main()
{
	vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto iter = vi.end() - 1, beg = vi.begin(); iter + 1 != beg; --iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	return 0;
}