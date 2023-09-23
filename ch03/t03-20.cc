#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int input;
    vector<int> v0;

    while (cin >> input)
        v0.push_back(input);

    for (auto i = 0; i < v0.size(); i += 2)
        cout << v0[i] + v0[i+1] << endl;

    for (decltype(v0.size()) i = 0, j = v0.size()-1; i <= j; ++i, --j)
        cout << v0[i] + v0[j] << endl;

    return 0;
}
