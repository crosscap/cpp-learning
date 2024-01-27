#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::map;
using std::ostream;
using std::set;
using std::string;
using std::vector;

void get_text(ifstream &infile, vector<string> &text)
{
	string line;

	while (getline(infile, line))
		text.push_back(line);
}

set<int> find_word_line(const string &finding, const vector<string> &text, map<string, set<int>> &words, int &counter)
{
	bool flag = false;
	string word;
	vector<int> temp_result;

	counter = 0;
	for (int i = 0, end = text.size(); i != end; ++i) {
		flag = false;
		istringstream sstrm(text[i]);
		while (sstrm >> word) {
			if (word == finding) {
				if (!flag) {
					flag = true;
					temp_result.push_back(i);
				}
				++counter;
			}
		}
	}
	words[finding] = set<int>(temp_result.begin(), temp_result.end());

	return words[finding];
}

ostream &print(ostream &outfile, const string finding, const vector<string> &text, const set<int> &result, int counter)
{
	outfile << finding << " occurs " << counter << " times" << endl;
	for (auto &r : result)
		cout << "\t(line " << r + 1 << " ) " << text[r] << endl;

	return outfile;
}

int main()
{
	ifstream infile("input.txt");
	int counter;
	vector<string> text;
	map<string, set<int>> words;
	set<int> result;

	get_text(infile, text);

	do {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		result = find_word_line(s, text, words, counter);
		print(cout, s, text, result, counter) << endl;
	} while (true);

	return 0;
}