#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::bind;
using std::cin;
using std::cout;
using std::endl;
using std::partition;
using std::sort;
using std::string;
using std::unique;
using std::vector;

using namespace std::placeholders;

void elimDups(vector<string> &vs);
void beggies(vector<string> &words, vector<string>::size_type sz);
bool check_size(const string &s, string::size_type sz);
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
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		 << " of length " << sz << " or longer" << endl;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
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