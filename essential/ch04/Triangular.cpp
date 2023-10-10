#include "Triangular.h"
#include <algorithm>

vector<int> Triangular::_elems;

Triangular::Triangular(int len, int bp)
    :_length(len > 0 ? len : 1), _beg_pos (bp > 0 ? bp : 1)
{
    _next = _beg_pos - 1;
    int elem_cnt = _beg_pos + _length - 1;
    if (_elems.size() < elem_cnt) {
        gen_elements(elem_cnt);
    }
}

int Triangular::elem(int pos) const
{
    return _elems[_beg_pos + pos];
}

bool Triangular::next(int &val) const
{
    return _elems[_beg_pos + _next++];
}

Triangular& Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs)
    {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }

    return *this;
}

bool Triangular::is_elem(int value)
{
    if (!_elems.size() || _elems[_elems.size()-1] < value)
        gen_elems_to_value(value);
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = std::find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length)
{
    if (length < 0 || length > _max_elems) {
        cerr << "length wrong!";
        return;
    }
    if (_elems.size() < length) {
        int ix = _elems.size() ? _elems.size() : 1;
        for (; ix <= length; ++ix) {
            _elems.push_back(ix * (ix + 1) / 2);
        }
    }
}

void Triangular::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if (!ix) {
        _elems.push_back(1);
        ix = 1;
    }
    while (_elems[ix-1] < value && ix < _max_elems) {
        ++ix;
        _elems.push_back(ix * (ix + 1) / 2);
    }
    if (ix == _max_elems)
        cerr << "Triangular Sequence: opps: value too large "
             << value << " -- exceeds max size of "
             << _max_elems << endl;
}

void Triangular::display(int length, int beg_pos, ostream &os)
{
    int elem_cnt = beg_pos + length - 1;
    for (int ix = beg_pos - 1; ix < elem_cnt; ++ix)
        os << _elems[ix] << ' ';
    os << endl;
}