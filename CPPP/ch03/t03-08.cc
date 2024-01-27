#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s;
	int i = 0;
	cin >> s;

	while ( i < s.size()) {
		s[i] = 'X';
		++i; 
	}
	cout << s << endl;

	cin >> s;
	for (int j = 0; j < s.size(); ++j)
		s[j] = 'X';
	cout << s << endl;

	return 0;
}