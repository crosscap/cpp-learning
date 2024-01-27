#include <iostream>
#include <list>
#include <vector>
#include <string>


using std::cout;
using std::ostream;

using std::list;
using std::vector;
using std::string;

template<typename elemtype>
ostream &show_vector(const vector<elemtype> vi, ostream &os = cout);

int main()
{
    list<const char *> lcp{"go", "cs", "csgo", "cs2"};
    vector<string> vs;

    vs.assign(lcp.cbegin(), lcp.cend());
    show_vector(vs);

    return 0;
}

template<typename elemtype>
ostream &show_vector(const vector<elemtype> vi, ostream &os)
{
    for (auto beg = vi.begin(); beg != vi.end(); ++beg) {
        os << *beg << " ";
    }
    os << std::endl;
    return os;
}