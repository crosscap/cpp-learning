#include "normal.h"

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os)
{
    vector<elemType>::const_iterator iter = vec.begin();
    vector<elemType>::const_iterator end_it = vec.end();

    for (; iter != endit; ++iter)
        os << *iter << ' ';
    os << endl;
}