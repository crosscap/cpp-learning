#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string input;
	vector<string> carrier;

	while (cin >> input)
		carrier.push_back(input);
	for (auto &i : carrier)
		for (auto &j : i)
			j = toupper(j);
	for (auto word : carrier)
		cout << word << endl;
	cout << endl;
	
	return 0;
}