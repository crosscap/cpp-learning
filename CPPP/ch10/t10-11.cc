#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;

void elimDups(vector<string> &vs);
void display_vs(const vector<string> &vs);
bool isShorter(const string &s1, const string &s2);

int main()
{
	string input;
	vector<string> vs;
	std::ifstream input_file("story.txt");

	while (input_file >> input) {
		vs.push_back(input);
	}
	elimDups(vs);
	stable_sort(vs.begin(), vs.end(), isShorter);
	display_vs(vs);

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

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}