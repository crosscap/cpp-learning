#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using std::count;
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int counter;
    string input;
    list<string> ls;
    std::ifstream input_file("numbers.txt");

    cout << "Enter some numbers.\n";
    while (input_file >> input) {
        ls.push_back(input);
    }
    cout << "Enter the number you want to count.\n";
    cin >> input;
    counter = count(ls.begin(), ls.end(), input);
    std::printf("Have %d of %d in the vector.\n", counter, input);

    return 0;
}