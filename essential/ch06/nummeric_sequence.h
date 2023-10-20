#include <vector>
using namespace std;

template<void (*pf)(int pos, vector<int> &seq)>
class nummeric_sequence {
public:
    nummeric_sequence(int len, int beg_pos = 1)
    {
        if (!pf)
            return;
        _len = len > 0 ? len : 1;
        _beg_pos = beg_pos > 0 ? beg_pos : 1;
        pf(beg_pos+len-1, _elems);
    }
private:
    int _len;
    int _beg_pos;
    vector<int> _elems;
};