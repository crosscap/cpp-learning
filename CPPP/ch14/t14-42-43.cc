#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::bind;
using std::greater;
using std::not_equal_to;
using std::string;
using std::vector;

using namespace std::placeholders;

// t14-43
bool dividedByAll(int num, const std::set<int> &si)
{
	return std::count_if(si.begin(), si.end(), bind(std::modulus<int>(), num, _1)) == 0;
}

int main()
{
	std::vector<int> vi{1896, 78, 827, 2767, 9972, 67, 2, 837, 2983, 1010};
	std::vector<std::string> vs{"pooh", "go", "tathe"};
	std::set<int> divided{2, 4, 6};

	// a
	std::cout << std::count_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 1024)) << std::endl;
	// b
	std::cout << *std::find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "pooh")) << std::endl;
	// c
	std::transform(vi.begin(), vi.end(), vi.begin(), bind(std::multiplies<int>(), _1, 2));
	for (auto r : vi)
		std::cout << r << " ";
	std::cout << std::endl;

	// t14-43
	std::cout << (dividedByAll(24, divided) ? "canbe" : "can't") << std::endl;
	return 0;
}
