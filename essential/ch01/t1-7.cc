#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	ifstream in_file(".\\input-07.txt");
	if (!in_file) {
		cout << "can not open input file!";
		return -1;
	}
	ofstream out_file(".\\output-07.txt");
	if (!out_file) {
		cout << "can not open output file!";
		return -2;
	}
	string str;
	vector<string> words;

	while (in_file >> str) {
		while (!isalnum(str[str.size() - 1])) {
			str.pop_back();
		}
		words.push_back(str);
	}
	for (int i = 0; i != words.size(); ++i) {
		cout << words[i] << " ";
	}
	cout << endl;
	sort(words.begin(), words.end());
	for (int i = 0; i != words.size(); ++i) {
		cout << words[i] << " ";
	}
	cout << endl;
	for (int i = 0; i != words.size(); ++i) {
		out_file << words[i] << '\n';
	}
	out_file << endl;

	return 0;
}