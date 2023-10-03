#include <iostream>

using namespace std;

const int MAXSIZE = (20+1);

int main()
{
	char name[MAXSIZE];
	bool long_enough = false;

	cout << "What's your name?\n";
	cin >> name;
	while (!long_enough) {
		int length;
		for (length = 0; name[length]; ++length)
			continue;
		if (length <= 2) {
			cout << "Too short! Please enter a right name." << endl;
			cin >> name;
		}
		else
			long_enough = true;
	}

	cout << "Hello, " << name << " ... and goodbye!" << endl;

	return 0;
}