#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main()
{
    vector<int> v0;
    int input;

    while (cin >> input)
        v0.push_back(input);
    for (auto i = v0.begin(); i != v0.end(); ++i)
    {
        *i = *i % 2 ? *i * 2 : *i;
    }
    for (auto i = v0.begin(); i != v0.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << std::endl;

    return 0;
}