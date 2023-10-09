#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	bool long_enough = false;

	cout << "What's your name?\n";
	cin >> name;
	while (!long_enough) {
		if (name.size() <= 2) {
			cout << "Too short! Please enter a right name." << endl;
			cin >> name;
		} else
			long_enough = true;
	}

	cout << "Hello, " << name << " ... and goodbye!" << endl;

	return 0;
}