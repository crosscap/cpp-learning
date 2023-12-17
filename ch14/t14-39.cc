#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void clean_word(string &str);

class StringSizeBigger
{
public:
	StringSizeBigger(size_t sz)
		: sz(sz) { }
	bool operator()(const string &str) const { return str.size() >= sz; }

private:
	size_t sz;
};

class StringSizeSmaller
{
public:
	StringSizeSmaller(size_t sz)
		: sz(sz) { }
	bool operator()(const string &str) const { return str.size() < sz; }

private:
	size_t sz;
};

int main()
{
	string words;
	ifstream ifile("input.txt");
	vector<string> vs;
	StringSizeBigger cmpbig(10);
	StringSizeSmaller cmpsmall(10);
	while (ifile >> words) {
		clean_word(words);
		vs.push_back(words);
	}

	cout << "size of words between 1 to 9 is: ";
	for (auto r : vs) {
		if (cmpsmall(r)) {
			cout << r << " ";
		}
	}
	cout << endl;
	cout << "size of words more than 10 is: ";
	for (auto r : vs) {
		if (cmpbig(r)) {
			cout << r << " ";
		}
	}
	cout << endl;

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
