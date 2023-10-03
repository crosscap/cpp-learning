#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream input(".\\input-07.txt");
	ofstream output(".\\output-07.txt");
	string str;
	vector<string> words;

	while (input >> str) {
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
		output << words[i] << '\n';
	}

	return 0;
}