#include <iostream>
#include <vector>

using std::vector;

template<typename elemtype>
std::ostream &
show_vector(const vector<elemtype> vi, std::ostream &os)
{
    for (auto beg = vi.begin(); beg != vi.end(); ++beg) {
        os << *beg << " ";
    }
    os << std::endl;
    return os;
}