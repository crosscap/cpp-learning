#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int input;
	vector<int> v0;

	while (cin >> input)
		v0.push_back(input);

	for (auto ib = v0.cbegin(); ib != v0.cend() && ib+1 != v0.cend(); ib += 2)
		cout << *ib + *(ib+1) << endl;

	for (auto ib = v0.cbegin(), ie = v0.cend()-1; ib <= ie; ++ib, --ie)
		cout << *ib + *ie << endl;

	return 0;
}
