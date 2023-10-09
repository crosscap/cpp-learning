#include <algorithm>
#include "normal.h"

vector<int> sub_vec(const vector<int> &vec, int val)
{
    vector<int> local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    vector<int>::iterator iter =
        find_if(local_vec.begin(), local_vec.end(),
                bind2nd(greater<int>(), val));
    local_vec.erase(iter, local_vec.end());

    return local_vec;
}