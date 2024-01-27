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
    vector<int> v0(MAXSIZE, 0);
    for (auto i = 0;i < MAXSIZE; ++i)
        v0[i] = i;
    int ia[MAXSIZE];
    for (auto i = 0;i < MAXSIZE; ++i)
        ia[i] = v0[i];
    for (auto i : ia)
        cout << i << " ";
    cout << endl;

    return 0;
}