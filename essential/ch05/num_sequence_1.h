#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence() {};

    virtual const char * what_am_i() const = 0;

    int elem(int) const;
    ostream& print(ostream &os = cout) const;

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

const int num_sequence::_max_elems = 1024;

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
