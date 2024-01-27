#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::regex;
using std::regex_search;
using std::smatch;
using std::string;

int main()
{
	string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	regex r(pattern);
	smatch results;
	string test_str;

	cout << "enter a word to check it: ";
	while (cin >> test_str)
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;
		else
			cout << "don't have string fit to regex" << endl;

	return 0;
}