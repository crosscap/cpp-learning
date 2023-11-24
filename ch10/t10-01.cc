#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int input, counter;
	vector<int> vi;
	std::ifstream input_file("numbers.txt");

	while (input_file >> input) {
		vi.push_back(input);
	}
	cout << "Enter the number you want to count.\n";
	cin >> input;
	counter = count(vi.begin(), vi.end(), input);
	std::printf("Have %d of %d in the vector.\n", counter, input);

	return 0;
}