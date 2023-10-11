#include <iostream>
#include <string>
#include <vector>
#include "Triangular_iterator.h"

using namespace std;

class Triangular
{
public:
    friend class Triangular_iterator;

    Triangular(int len = 1, int bp = 1);

    int length() const { return _length; }
    void length(int len) { _length = len; }
    int beg_pos() const { return _beg_pos; }
    void beg_pos(int bp) { _beg_pos = bp; }
    int elem(int pos) const;

    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos - 1; }
    Triangular &copy(const Triangular &rhs);

    static bool is_elem(int value);
    static void gen_elements(int);
    static void gen_elems_to_value(int);
    static void display(int length, int beg_pos, ostream &os = cout);

    typedef Triangular_iterator iterator;
    Triangular_iterator begin() const
    {
        return Triangular_iterator(_beg_pos);
    }

    Triangular_iterator end() const
    {
        return Triangular_iterator(_beg_pos+_length);
    }

private:
    int _length;
    int _beg_pos;
    mutable int _next;
    static vector<int> _elems;
    static const int _max_elems = 1024;
};
