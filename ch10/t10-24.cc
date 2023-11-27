#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::bind;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;

using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int firstBigger(const vector<int> &vi, const string &str)
{
	return *find_if(vi.cbegin(), vi.cend(), bind(check_size, str, _1));
}