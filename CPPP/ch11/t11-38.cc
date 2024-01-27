// 将程序中的 map 修改为 unordered_map 即可
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using std::unordered_map;
using std::set;
using std::string;

int main()
{
	string word;
	unordered_map<string, size_t> word_count;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                       "the", "but", "and", "or", "an", "a"};

	while (std::cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;

	return 0;
}