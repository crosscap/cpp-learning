#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::stable_partition;
using std::string;
using std::unique;
using std::vector;

void elimDups(vector<string> &vs);
void beggies(vector<string> &words, vector<string>::size_type sz);
void display_vs(const vector<string> &vs);
string make_plural(int i, const string &word, const string &behind);

void elimDups(vector<string> &vs)
{
	sort(vs.begin(), vs.end());
	auto end_unique = unique(vs.begin(), vs.end());
	vs.erase(end_unique, vs.end());
}

void beggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	auto wc = stable_partition(words.begin(), words.end(),
	                           [sz](const string &a) { return a.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		 << " of length " << sz << " or longer" << endl;
}

void display_vs(const vector<string> &vs)
{
	for (auto &rs : vs)
		cout << rs << " ";
	cout << endl;
}

string make_plural(int i, const string &word, const string &behind)
{
	return i > 1 ? word + behind : word;
}