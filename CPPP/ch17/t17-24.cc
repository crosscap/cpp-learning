#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_replace;
using std::string;
using std::regex_constants::format_first_only;

void chenge_phone24()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";

	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;
}

void chenge_phone25()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";

	while (getline(cin, s))
		cout << regex_replace(s, r, fmt, format_first_only) << endl;
}

void chenge_phone26()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";

	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;
}