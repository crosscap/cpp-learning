#include <iostream>
#include <vector>

using std::vector;

template<typename elemtype>
std::ostream
&show_vector(const vector<elemtype> vi, std::ostream &os = std::cout);

int main()
{
    vector<int> vi1(10, 7);
    vector<int> vi2(10, 8);
    vector<int> &rvi1 = vi1;
    vector<int> &rvi2 = vi2;
    vector<int> *pvi1 = &vi1;
    vector<int> *pvi2 = &vi2;
    auto vi1beg = vi1.begin();
    auto vi2beg = vi2.begin();

    show_vector(vi1) << std::endl;
    show_vector(vi2) << std::endl;

    std::swap(vi1, vi2);
    show_vector(vi1) << std::endl;
    show_vector(vi2) << std::endl;
    show_vector(rvi1) << std::endl;
    show_vector(*pvi1) << std::endl;
    std::cout << *vi1beg << "\n" << std::endl;

    return 0;
}

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