#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int input, sum;
	vector<int> vi;
	std::ifstream input_file("numbers.txt");

	while (input_file >> input) {
		vi.push_back(input);
	}
	sum = accumulate(vi.begin(), vi.end(), 0);
	std::printf("Sum of numbers in the vector is %d.\n", sum);

	return 0;
}