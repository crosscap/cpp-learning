#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::map;
using std::set;
using std::string;

void clean_word(string &str);

int main()
{
	std::ifstream inf("input.txt");
	map<string, size_t> word_count;
	set<string> exclude = {"the", "but", "and", "or", "an", "a"};
	string word;

	while (inf >> word) {
		clean_word(word);
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}

	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
				  << (w.second > 1 ? " times" : " time") << std::endl;

	return 0;
}

void clean_word(string &str)
{
	for (auto iter = str.begin(); iter != str.end();) {
		if (iter == str.end() - 1 && !isalnum(*iter))
			iter = str.erase(iter);
		else {
			*iter = tolower(*iter);
			++iter;
		}
	}
}