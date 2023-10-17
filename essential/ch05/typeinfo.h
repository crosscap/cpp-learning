#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence() {};

    int elem(int) const;
    ostream& print(ostream &os = cout) const;
    const char * what_am_i() const { return typeid(*this).name(); }

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    static int max_elems() { return _max_elems; }

protected:
    num_sequence(int len, int bp, vector<int> &re)
        : _length(len), _beg_pos(bp), _relems(re) { }

    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    const static int _max_elems = 1024;

    int _length;
    int _beg_pos;
    vector<int> &_relems;
};

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len, int beg_pos)
        : num_sequence(len, beg_pos, _elems) { }

protected:
    virtual void gen_elems(int pos) const;

    static vector<int> _elems;
};

const int num_sequence::_max_elems = 1024;
vector<int> Fibonacci::_elems;

bool num_sequence::check_integrity(int pos, int size) const
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

int num_sequence::elem(int pos) const
{
    if (!check_integrity(pos, _relems.size()))
        return 0;
    if (pos > _relems.size())
        gen_elems(pos);

    return _relems[pos - 1];
}

ostream& num_sequence::print(ostream &os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _relems.size())
        num_sequence::gen_elems(end_pos);

    while (elem_pos < end_pos)
        os << _relems[elem_pos++] << ' ';
    os << endl;

    return os;
}

ostream& operator<<(ostream &os, const num_sequence &ns)
{
    return ns.print(os);
}

void Fibonacci::gen_elems(int pos) const
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
