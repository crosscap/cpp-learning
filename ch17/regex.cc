#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
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
	std::string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	std::regex r(phone);
	std::smatch m;
	std::string s;

	if (std::getline(std::cin, s))
		for (std::sregex_iterator it(s.begin(), s.end(), r), endit; it != endit; ++it)
			if (valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
}

bool vaild(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}