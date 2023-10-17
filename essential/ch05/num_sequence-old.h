#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    typedef void (num_sequence::*PtrType) (int);

    enum ns_type {
        ns_unset, ns_fibonacci, ns_lucas, ns_pell, 
        ns_triangular, ns_square, ns_pentagonal
    };

    void fibonacci(int);
    void lucas(int);
    void pell(int);
    void triangular(int);
    void square(int);
    void pentagonal(int);

    int elem(int);
    int elem(int) const;
    bool check_integrity(int);
    const char * what_am_i() const;

    static ns_type nstype(int num)
    {
        return num <= 0 || num >= num_seq
            ? ns_unset
            : static_cast<ns_type>(num);
    }

    void set_sequence(ns_type nst);

private:
    vector<int>* _elem;
    PtrType _pmf;
    ns_type _isa;

    static const int num_seq = 7;
    static PtrType func_tbl[num_seq];
    static vector<vector<int> > seq;
};

const int num_sequence::num_seq;
num_sequence::PtrType num_sequence::func_tbl[num_sequence::num_seq];
vector<vector<int> > num_sequence::seq;
num_sequence::PtrType num_sequence::func_tbl[num_seq] = {
    0,
    & num_sequence::fibonacci,
    & num_sequence::lucas,
    & num_sequence::pell,
    & num_sequence::triangular,
    & num_sequence::square,
    & num_sequence::pentagonal
};

int num_sequence::elem(int pos)
{
    if (!check_integrity(pos))
        return 0;

    if (pos > _elem->size())
        (this->*_pmf)(pos);

    return (*_elem)[pos - 1];
}

void num_sequence::set_sequence(ns_type nst)
{
    switch (nst) {
    default: 
        cerr << "invalid type: setting to 0\n";
    case ns_unset:
        _pmf = 0;
        _elem = 0;
        _isa = ns_unset;
        break;
    case ns_fibonacci: case ns_pell: case ns_lucas:
    case ns_triangular: case ns_square: case ns_pentagonal:
        _pmf = func_tbl[nst];
        _elem = &seq[nst];
        _isa = nst;
        break;
    }
}

inline void display(ostream &os, const num_sequence &ns, int pos)
{
    os << "The element at position "
       << pos << " for the "
       << ns.what_am_i() << " sequence is "
       << ns.elem(pos) << endl;
}

const char * num_sequence::what_am_i() const
{
    static char *names[num_seq] = {
        "notSet",
        "fibonacci", "lucas", "pell",
        "triangular", "square", "pentagonal"
    };

    return names[_isa];
}