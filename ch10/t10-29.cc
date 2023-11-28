#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::istream_iterator;
using std::string;
using std::vector;

int main()
{
	istream_iterator<string> str_iter(std::cin), eof;
	vector<string> vs;

	while (str_iter != eof)
		vs.push_back(*str_iter++);
	for (auto &rs : vs)
		std::cout << rs << " ";
	std::cout << std::endl;

	return 0;
}