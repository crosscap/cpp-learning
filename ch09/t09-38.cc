#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vi;

	for (int i = 0; i != 100; ++i) {
		std::cout << "size: " << vi.size() << " "
		          << "capacity: " << vi.capacity() << std::endl;
		vi.push_back(0);
	}

	return 0;
}