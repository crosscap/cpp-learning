#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class isEqual
{
public:
	isEqual(int i = 0)
		: val(i) { }
	bool operator()(int comp) { return val == comp; }

private:
	int val;
};

int main()
{
	vector<int> vi{5, 6, 7, 8, 9, 5, 4, 3, 4, 5, 6, 7, 7, 8, 9, 8, 10};

	std::replace_if(vi.begin(), vi.end(), isEqual(7), 5);
	for (auto r : vi)
		std::cout << r << " ";
	std::cout << std::endl;

	return 0;
}