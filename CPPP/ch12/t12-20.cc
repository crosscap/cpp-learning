#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

#include "StrBlob.h"

using std::string;

int main()
{
	std::ifstream inf("input.txt");
	string word;
	StrBlob words;

	while (getline(inf, word)) {
		words.push_back(word);
	}
	for (StrBlobPtr beg = words.begin(), end = words.end(); !StrBlobPtrEqual(beg, end); beg.incr()) {
		std::cout << beg.deref() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}