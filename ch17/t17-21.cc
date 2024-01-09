#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using std::regex;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;
using std::string;
using std::vector;

struct PersonInfo;

bool valid(const string &);
std::string format(const string &);

int main()
{
	string line, word;
	vector<PersonInfo> people;
	std::fstream input("PersonInfo.txt");
	while (getline(input, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	std::string phone("(\\()?(\\d{3})(\\))?([.- ])?(\\d{4})");
	std::regex r(phone);
	std::smatch m;
	for (const auto &entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			regex_search(nums, m, r);
			if (!valid(m))
				badNums << " " << nums;
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << "invalid number(s) "
					  << badNums.str() << std::endl;
	}
}

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}
