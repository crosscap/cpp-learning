#include <iostream>
#include "num_sequence_1.h"
using namespace std;

class Fibonacci : public num_sequence
{
public:
    Fibonacci(int len, int beg_pos)
        : num_sequence(len, beg_pos, _elems) { }

    virtual const char * what_am_i() const { return "Fibonacci"; }

protected:
    virtual void gen_elems(int pos) const;

    static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

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
