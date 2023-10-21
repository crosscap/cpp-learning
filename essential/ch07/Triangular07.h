#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Triangular
{
    friend class Triangular_iterator;
public:
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

protected:
    int _length;
    int _beg_pos;
    mutable int _next;
    static vector<int> _elems;
    static const int _max_elems = 1024;
};

#include <string>
#include <iostream>
using namespace std;

class Triangular_iterator
{
    friend class Triangular;
public:
    Triangular_iterator(int index) : _index(index-1) { }
    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator &operator++(); // prefix
    Triangular_iterator operator++(int); // postfix

private:
    void check_integrity () const;
    int _index;
};


// class Triangular_iterator
inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const
{
    return _index == rhs._index;
}

inline bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const
{
    return !(*this == rhs);
}

inline Triangular_iterator& Triangular_iterator::
operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::
operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}

inline void Triangular_iterator::
check_integrity () const
{
    if (_index >= Triangular::_max_elems) {
        iterator_overflow ex(_index, Triangular::_max_elems);
        throw ex;
    }
    if (_index >= Triangular::_elems.size())
        Triangular::gen_elements(_index + 1);
}

inline int Triangular_iterator::operator*() const
{
    check_integrity();
    return Triangular::_elems[_index];
}
ostream & operator<<(ostream &os, const Triangular &rhs)
{
    os << "(" << rhs.beg_pos() << ","
       << rhs.length() << ")";

    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

istream & operator>>(istream &is, Triangular &rhs)
{
    char ch1, ch2;
    int bp, len;

    is >> ch1 >> bp >> ch2 >> len;

    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();

    return is;
}

class iterator_overflow{
public:
    iterator_overflow(int index, int max)
        : _index(index), _max(max) { }

    int index() { return _index; }
    int max() { return _max; }

    void what_happened(ostream &os = cerr)
    {
        os << "Internal error: current index " << _index
           << " exceeds maximum bound: " << _max << endl;
    }
private:
    int _index;
    int _max;
};