#include <algorithm>
#include <functional>
#include "normal.h"

vector<int> filter_ver2(const vector<int> &vec, int val, less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    while ((iter =
            find_if(iter, vec.end(), bind2nd(lt, val))) != vec.end()) {
        nvec.push_back(*iter);
        ++iter;
    }

    return nvec;
}