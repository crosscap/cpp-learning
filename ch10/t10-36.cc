#include <algorithm>
#include <iostream>
#include <list>

using std::find;
using std::list;

int main()
{
	list<int> li{1, 0, 2, 3, 4, 5, 0, 6, 7, 8, 9};
	auto lastzero = find(li.rbegin(), li.rend(), 0);
	std::cout << *(++lastzero) << std::endl;

	return 0;
}