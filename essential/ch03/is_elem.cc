#include <algorithm>
#include "normal.h"

extern bool grow_vec(vector<int> &, int);

bool is_elem(vector<int> &vec, int elem)
{
    int max_value = *(max_element(vec.begin(), vec.end()));
    // In GCC 8.1.0 max_element() will return a pointer instead of value.
    // Up statement can be take place with down statement.
    // int max_value = vec.empty() ? 0 : vec[vec.size()-1];
    if (max_value < elem)
        return grow_vec(vec, elem);
    if (max_value == elem)
        return true;
    return binary_search(vec.begin(), vec.end(), elem);
}