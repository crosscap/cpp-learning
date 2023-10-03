#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> vi(10, 3);

	for (auto pi = vi.begin(); pi != vi.end(); ++pi) {
		*pi *= 2;
	}
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}