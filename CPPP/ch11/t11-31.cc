#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::multimap;
using std::string;
using std::vector;

int main()
{
	multimap<string, string> books;
	string input;
	books.insert("Mark Twain", "Tom Sawyer");
	books.insert("Mark Twain", "Million pounds");
	books.insert("Mark Twain", "A prince and a pauper");
	books.insert("Hemingway", "The Old Man and the Sea");
	books.insert("Hemingway", "The Sun Also Rises");
	std::cin >> input;
	auto pos = books.equal_range(input);
	if (pos.first != pos.second) {
		books.erase(pos.first, pos.second);
	}
}