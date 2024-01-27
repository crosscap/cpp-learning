#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::map;
using std::set;
using std::string;

int main()
{
	std::ifstream inf("input.txt");
	map<string, size_t> word_count;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                       "the", "but", "and", "or", "an", "a"};
	string word;

	while (inf >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;

	return 0;
}