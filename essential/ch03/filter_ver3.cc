#include <algorithm>
#include <functional>
#include "normal.h"

template <typename InputIterator, typename OutputIterator,
          typename ElemType, typename Comp>
OutputIterator
filter_ver3(InputIterator first, InputIterator last,
            OutputIterator at, const ElemType &val, Comp pred)
{
    while ((first =
            find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "find value: " << *first << endl;
        *at++ = *first++;
    }

    return at;
}