#include <iostream>
#include <string>
#include <vector>

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
	cout << "input end" << endl;
	for (auto i : carrier)
		cout << i << endl;
	
	return 0;
}