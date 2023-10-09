#include "normal.h"

const int* find(const vector<int> &vec, int value)
{
    for (int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] == value) {
            return &vec[ix];
        }
    return nullptr;
}
