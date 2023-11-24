#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::partition;
using std::string;
using std::vector;

void elimDups(vector<string> &vs);
void display_vs(const vector<string> &vs);
vector<string>::iterator have_ge_5(vector<string> &vs);
bool isShorter(const string &s1, const string &s2);
bool is_ge_5(const string &s);

int main()
{
	string input;
	vector<string> vs;
	std::ifstream input_file("story.txt");

	while (input_file >> input) {
		vs.push_back(input);
	}
	elimDups(vs);
	auto be5_end = partition(vs.begin(), vs.end(), is_ge_5);
	display_vs(vs);
	for (auto ps = vs.begin(), end_vs = vs.end(); ps != be5_end; ++ps)
		cout << *ps << " ";
	cout << endl;

	return 0;
}

void elimDups(vector<string> &vs)
{
	display_vs(vs);
	sort(vs.begin(), vs.end());
	display_vs(vs);
	auto end_unique = unique(vs.begin(), vs.end());
	display_vs(vs);
	vs.erase(end_unique, vs.end());
	display_vs(vs);
}

void display_vs(const vector<string> &vs)
{
	for (auto &rs : vs) {
		cout << rs << " ";
	}
	cout << endl;
}

vector<string>::iterator have_ge_5(vector<string> &vs)
{
	auto part_end = partition(vs.begin(), vs.end(), is_ge_5);
	return part_end;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool is_ge_5(const string &s)
{
	return s.size() >= 5;
}