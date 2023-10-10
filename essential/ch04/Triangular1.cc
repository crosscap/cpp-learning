#include "Triangular1.h"

Triangular1::Triangular1(int len, int bp)
    : _name("Triangular")
{
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos - 1;
}

Triangular1::Triangular1(const Triangular1 &rhs)
    : _name("Triangular"), _length(rhs._length), 
      _beg_pos(rhs._beg_pos), _next(rhs._beg_pos-1)
{
    
}