#include <deque>
#include <list>

using std::deque;
using std::list;

const list<int>
&detach_even_odd(const list<int> &li, deque<int> &d_odd, deque<int> &d_even)
{
    for (auto lbeg = li.cbegin(), lend = li.cend(); lbeg != lend; ++lbeg) {
        if (*lbeg % 2)
            d_odd.push_back(*lbeg);
        else
            d_even.push_back(*lbeg);
    }

    return li;
}