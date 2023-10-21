#include "Triangular.h"
#include "Triangular_iterator.h"

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
    if (_index >= Triangular::_max_elems)
        // throw iterator_overflow();
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