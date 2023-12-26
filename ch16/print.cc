#include <algorithm>
#include <iostream>

using std::begin;
using std::end;
using std::endl;
using std::cout;

template <typename elemType, size_t size>
void print(const elemType (&a)[size])
{
    for (auto iter = begin(a), en = end(a); iter != en; ++iter)
        cout << *iter << ' ';
    cout << endl;
}