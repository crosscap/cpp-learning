#include <iostream>
#include <map>
#include <set>
#include <string>

using std::map;
using std::set;
using std::string;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                       "the", "but", "and", "or", "an", "a"};
	string word;

	while (std::cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];

	map<string, size_t>::const_iterator map_it = word_count.cbegin();
	while (map_it != word_count.cend()) {
		std::cout << map_it->first << " occurs " << map_it->second
		<< (map_it->second > 1 ? " times" : " time") << std::endl;
	}

	return 0;
}