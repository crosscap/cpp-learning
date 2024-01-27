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

class StringSizeEqual
{
public:
	StringSizeEqual(size_t sz)
		: sz(sz) { }
	bool operator()(const string &str) const { return str.size() == sz; }

private:
	size_t sz;
};

int main()
{
	string words;
	ifstream ifile("input.txt");
	vector<string> vs;
	while (ifile >> words) {
		clean_word(words);
		vs.push_back(words);
	}
	for (int i = 1; i <= 10; ++i) {
		StringSizeEqual comparer(i);
		cout << "size of words equal to " << i << " is: ";
		for (auto r : vs) {
			if (comparer(r)) {
				cout << r << " ";
			}
		}
		cout << endl;
	}

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
