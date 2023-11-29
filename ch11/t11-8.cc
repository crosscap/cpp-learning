#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::find;
using std::ifstream;
using std::string;
using std::vector;

void clean_word(string &str);

int main()
{
	ifstream inf("input.txt");
	string word;
	vector<string> vs;

	while (inf >> word) {
		clean_word(word);
		if (find(vs.begin(), vs.end(), word) == vs.end())
			vs.push_back(word);
	}
	for (auto &rs : vs)
		std::cout << rs << " ";
	std::cout << std::endl;
}

void clean_word(string &str)
{
	for (auto iter = str.begin(); iter != str.end();) {
		if (!isalnum(*iter))
			iter = str.erase(iter);
		else {
			*iter = tolower(*iter);
			++iter;
		}
	}
}