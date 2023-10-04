#include <iostream>
using namespace std;

bool fibon_elem(int, int &);

int main()
{
	int pos;
	int going = true;
	while (going) {
		cout << "Please enter a position: ";
		cin >> pos;

		int elem;
		if (fibon_elem(pos, elem)) {
			cout << "elect # " << pos << " is " << elem << endl;
		} else {
			cout << "Sorry. Could not calculate element # " << pos << endl;
		}

		char next;
		cout << "Do you want to calculate other element? (y/n)" << endl;
		cin >> next;
		if (next == 'n' || next == 'N') {
			going = false;
		}
	}
	return 0;
}