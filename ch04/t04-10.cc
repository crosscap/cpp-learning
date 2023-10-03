#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
	int i, sum = 0;

	while (cin >> i && i != 42) {
		sum += i;
	}

	cout << sum << std::endl;
	
	return 0;
}