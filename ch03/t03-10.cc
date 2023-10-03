#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s;

	cin >> s;
	for (auto c : s) {
		if (!ispunct)
			cout << c;
	}
	cout << endl;

	return 0;
}