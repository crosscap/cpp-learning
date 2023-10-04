#include <iostream>
using namespace std;

bool fibon_elem(int, int &);

int main()
{
	int pos;
	cout << "Please enter a position: ";
	cin >> pos;

	int elem;
	if (fibon_elem(pos, elem)) {
		cout << "elect # " << pos << " is " << elem << endl;
	} else {
		cout << "Sorry. Could not calculate element # " << pos << endl;
	}

	return 0;
}