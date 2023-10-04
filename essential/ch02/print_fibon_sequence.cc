#include <iostream>
using namespace std;

bool print_fibon_sequence(int pos)
{
	if (pos <= 0 || pos > 1024) {
		cout << "invalid position: " << pos
			 << " -- cannot handle requst!\n";

		return false;
	}

	cout << "The Fibonacci Sequence for" << pos << " positions:\n\t";
	switch (pos) {
	default:
	case 2:
		cout << "1 ";
	case 1:
		cout << "1 ";
		break;
	}
	int elem;
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix) {
		elem = n_2 + n_1;
		n_2 = n_1;
		n_1 = elem;
		cout << elem << ((ix % 10) ? " " : "\n\t");
	}
	cout << endl;

	return true;
}
