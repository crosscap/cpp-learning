#include "normal.h"

template <typename elemType>
inline elemType* begin(const vector<elemType> &vec)
{
    return vec.empty() ? nullptr : &vec[0];
}

template <typename elemType>
inline elemType* end(const vector<elemType> &vec)
{
    return vec.empty() ? nullptr : &vec[vec.size()];
}