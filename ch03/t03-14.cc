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
    int input;
    vector<int> carrier;

    while (cin >> input)
        carrier.push_back(input);
    for (auto i : carrier)
        cout << i << endl;
    
    return 0;
}