#include "normal.h"

template <typename elemType>
elemType* find(const elemType *first, const elemType *last,
               const elemType &value);

int count_occurs(const vector<int> &vec, int val)
{
    vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0;

    while ((iter = find(iter, vec.end(), val)) != vec.end()) {
        ++occurs_count;
        ++iter;
    }

    return occurs_count;
}