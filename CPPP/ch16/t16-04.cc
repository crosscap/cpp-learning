#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::list;
using std::string;
using std::vector;

template <typename iter, typename elemType>
iter myFind(iter begin, iter end, const elemType &find);

int main()
{
	vector<int> vi{1, 2, 3, 4, 5};
	list<string> ls{"go", "val", "final"};
	cout << *myFind(vi.begin(), vi.end(), 1) << " "
		 << *myFind(ls.begin(), ls.end(), string("go")) << std::endl;

	return 0;
}

template <typename iter, typename elemType>
iter myFind(iter begin, iter end, const elemType &find)
{
	for (; begin != end; ++begin)
		if (*begin == find)
			break;
	return begin;
}