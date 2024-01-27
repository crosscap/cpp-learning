#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::sregex_iterator;
using std::regex_replace;
using std::string;

bool valid(const std::smatch &m);

void replace_zip()
{
	string zip("(//d{5})((-?)(//d{4}))?");
	regex r(zip);
	string s;
	string fmt = "$1-$2";

	while (getline(cin, s))
		for (sregex_iterator it(s.begin(), s.end(), r), endit; it != endit; ++it)
			if (valid(*it))
				cout << it->format(fmt) << endl;
			else
				cout << it->str() << endl;
}

bool valid(const std::smatch &m)
{
	return m[2].matched && m[2].str()[0] != '-';
}