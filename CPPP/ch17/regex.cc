#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;
using std::string;

bool valid(const std::smatch &m);

void cei_find()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string test_str = "receipt friend theif receive";

	if (regex_search(test_str, results, r))
		cout << results.str() << endl;
}

void cpp_find()
{
	regex r("([[:alpha:]]*+)\\.(cpp|cxx|cc)$", regex::icase);
	smatch results;
	string filename;

	while (cin >> filename)
		if (regex_search(filename, results, r))
			cout << results.str(1) << endl;
}

void use_regex_iter()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string file;

	for (sregex_iterator it(file.begin(), file.end(), r), endit; it != endit; ++it)
		cout << it->str() << endl;
}

void use_regex_sub_match()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string file;

	for (sregex_iterator it(file.begin(), file.end(), r), endit; it != endit; ++it) {
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << it->prefix().str().substr(pos) << "\n\t\t>>> "
			 << it->str() << " <<<\n"
			 << it->suffix().str().substr(0, 40)
			 << endl;
	}
}

void find_phone()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	smatch m;
	string s;

	if (getline(cin, s))
		for (sregex_iterator it(s.begin(), s.end(), r), endit; it != endit; ++it)
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
}

bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

void use_replace()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	string number = "(908) 555-1800";
	string fmt = "$2.$5.$7";

	cout << regex_replace(number, r, fmt) << endl;
}

void chenge_phone()
{
	string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";

	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;
}
