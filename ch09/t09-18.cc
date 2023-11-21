#include <deque>
#include <iostream>
#include <string>

using std::deque;
using std::string;

void input_string_deque(deque<string> &ds)
{
	string input_str;

	while (std::cin >> input_str) {
		ds.push_back(input_str);
	}
}

std::ostream &output_deque(const deque<string> &ds, std::ostream &os)
{
	for (auto beg = ds.cbegin(), end = ds.cend(); beg != end; ++beg) {
		os << *beg;
	}

	return os;
}