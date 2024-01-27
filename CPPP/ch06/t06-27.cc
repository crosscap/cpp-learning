#include <initializer_list>

int sum_init_list(const std::initializer_list<int> &li)
{
    int sum = 0;
    for (auto beg = li.begin(); beg != li.end(); ++beg) {
        sum += *beg;
    }
    return sum;
}