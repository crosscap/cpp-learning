#include "normal.h"

vector<int> filter_ver1(const vector<int> &vec,
                        int filter_value,
                        bool (*pred)(int, int))
{
    vector<int> nvec;

    for (int ix = 0; ix < vec.size(); ++ix) {
        if (pred(vec[ix], filter_value)) {
            nvec.push_back(vec[ix]);
        }
    }

    return nvec;
}