#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int ia[10] = {}, ib[10] = {};
    vector<int> v0(10, 0);

    for (int i = 0; i < 10; ++i)
        ia[i] = i;
    for (auto i = 0; i < 10; ++i)
        ib[i] = ia[i];
    for (auto i = 0; i < 10; ++i)
        v0[i] = ia[i];
    for (auto i : ib)
        cout << i << " ";
    cout << endl;
    for (auto i : v0)
        cout << i << " ";
    cout << endl;

    return 0;
}
