#include <algorithm>
#include "normal.h"

template <typename IteratorType, typename ElemType, typename Comp>
IteratorType sub_vec_iterator(const IteratorType &vec, ElemType val, Comp pred)
{
    IteratorType local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    typename IteratorType::iterator iter;
    iter = find_if(local_vec.begin(), local_vec.end(),
                   bind2nd(pred, val));
    local_vec.erase(iter, local_vec.end());

    return local_vec;
}

int main()
{
    const int elem_size = 8;

    vector<int> ivec = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec2(elem_size);

    ivec2 = sub_vec_iterator(ivec, elem_size, greater<int>());
    for (auto iter = ivec2.begin(); iter != ivec2.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    return 0;
}