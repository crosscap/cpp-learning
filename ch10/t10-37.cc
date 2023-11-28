#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::copy;
using std::back_inserter;
using std::list;
using std::vector;

void display_li(const list<int> &li);

int main()
{
	vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> li;
	vector<int>::reverse_iterator rend(vi.begin() + 2);
	vector<int>::reverse_iterator riter(vi.begin() + 7);
	copy(riter, rend, back_inserter(li));
	display_li(li);

	return 0;
}

void display_li(const list<int> &li)
{
	for (auto &ri : li)
		std::cout << ri << " ";
	std::cout << std::endl;
}