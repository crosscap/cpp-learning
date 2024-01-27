#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;

void input_string_list(list<string> &ls)
{
	string input_str;

	while (std::cin >> input_str) {
		ls.push_back(input_str);
	}
}

std::ostream &output_deque(const list<string> &ls, std::ostream &os)
{
	for (auto beg = ls.cbegin(), end = ls.cend(); beg != end; ++beg) {
		os << *beg;
	}

	return os;
}