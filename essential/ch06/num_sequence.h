#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

template<int len, int beg_pos>
class num_sequence {
public:
    virtual ~num_sequence() {};

    const char * what_am_i() const;

    int elem(int) const;
    ostream& print(ostream &os = cout) const;
    static int max_elems() { return _max_elems; }

protected:
    num_sequence(vector<int> *pe) : _pelems(pe) { }

    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    const static int _max_elems = 1024;
    vector<int> *_pelems;
};

template<int len, int beg_pos>
const int num_sequence<len, beg_pos>::_max_elems;

template<int len, int beg_pos>
bool num_sequence<len, beg_pos>::
check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elems) {
        cerr << "!!invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    if (pos > size)
        gen_elems(pos);

    return true;
}

template<int len, int beg_pos>
ostream& operator<<(ostream &os, const num_sequence<len, beg_pos> &ns)
{
    return ns.print(os);
}

template<int len, int beg_pos>
int num_sequence<len, beg_pos>::elem(int pos) const
{
    if (!check_integrity(pos, _pelems->size()))
        return 0;

    return (*_pelems)[pos - 1];
}

template<int len, int beg_pos>
const char *num_sequence<len, beg_pos>::
what_am_i() const
{
    return typeid(*this).name();
}

template<int len, int beg_pos>
ostream& num_sequence<len, beg_pos>::
print(ostream &os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (!check_integrity(end_pos, _pelems->size()))
        return os;

    os << "( " << beg_pos << " , " << len << " ) ";
    while (elem_pos < end_pos)
        os << (*_pelems)[elem_pos++] << ' ';
    os << endl;

    return os;
}

template<int len, int beg_pos=1>
class Fibonacci : public num_sequence<len, beg_pos>{
public:
    Fibonacci() : num_sequence<len, beg_pos>(&_elems) { }

    virtual const char * what_am_i() const { return "Fibonacci"; }

protected:
    virtual void gen_elems(int pos) const;

    static vector<int> _elems;
};

template<int len, int beg_pos>
vector<int> Fibonacci<len, beg_pos>::_elems;

template<int len, int beg_pos>
void Fibonacci<len, beg_pos>::
gen_elems(int pos) const
{
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }

    if (_elems.size() <= pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix-2];
        int n_1 = _elems[ix-1];

        for (; ix <= pos; ++ix) {
            int elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}