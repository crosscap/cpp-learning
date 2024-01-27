#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vi(std::begin(ia), std::end(ia));
	list<int> li(std::begin(ia), std::end(ia));

	for (auto pvi = vi.begin(); pvi != vi.end();)
		if (*pvi % 2)
			pvi = vi.erase(pvi);
		else
			++pvi;
	for (auto pli = li.begin(); pli != li.end();)
		if (!(*pli % 2))
			pli = li.erase(pli);
		else
			++pli;
	for (auto &rvi : vi)
		std::cout << rvi << " ";
	std::cout << std::endl;
	for (auto &rli : li)
		std::cout << rli << " ";
	std::cout << std::endl;
	return 0;
}