#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using std::count;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int input, counter;
    vector<int> vi;
    std::ifstream input_file("numbers.txt");

    cout << "Enter some numbers.\n";
    while (input_file >> input) {
        vi.push_back(input);
    }
    cout << "Enter the number you want to count.\n";
    cin >> input;
    counter = count(vi.begin(), vi.end(), input);
    std::printf("Have %d of %d in the vector.\n", counter, input);

    return 0;
}