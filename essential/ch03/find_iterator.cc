#include "normal.h"
#include <list>

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last,
                  const elemType &value)
{
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return last;
}