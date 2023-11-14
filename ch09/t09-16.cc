#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

bool vector_list_int_equal(vector<int> &vi, list<int> &li)
{
    if (vi.size() != li.size())
        return false;
    auto vibeg = vi.begin(), viend = vi.end();
    auto libeg = li.begin();
    for (; vibeg != viend; ++vibeg, ++libeg)
        if (*vibeg != *libeg)
            return false;
    return true;
}