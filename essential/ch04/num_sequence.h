#include <vector>
using namespace std;
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);

num_sequence::PtrType num_sequence::func_tbl[num_seq] = {
    0,
    & num_sequence::fibonacci,
    & num_sequence::lucas,
    & num_sequence::pell,
    & num_sequence::triangular,
    & num_sequence::square,
    & num_sequence::pentagonal
};
class num_sequence
{
public:
    typedef void (num_sequence::*PtrType) (int);

    void fibonacci(int);
    void lucas(int);
    void pell(int);
    void triangular(int);
    void square(int);
    void pentagonal(int);

    int elem(int);
    bool check_integrity(int);

private:
    vector<int>* _elem;
    PtrType _pmf;
    static const int num_seq = 7;
    static PtrType func_tbl[num_seq];
    static vector<vector<int> > seq;
};

int num_sequence::elem(int pos)
{
    if (!check_integrity(pos))
        return 0;

    if (pos > _elem->size())
        (this->*_pmf)(pos);

    return (*_elem)[pos - 1];
}