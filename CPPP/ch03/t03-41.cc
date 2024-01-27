#include <iostream>
#include <vector>
#include <iterator>

#define MAXSIZE 10

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int ia[MAXSIZE];
    for (auto i = 0;i < MAXSIZE; ++i)
        ia[i] = i;
    vector<int> v0(std::begin(ia), std::end(ia));

    for (auto i : v0)
        cout << i << " ";
    cout << endl;

    return 0;
}
