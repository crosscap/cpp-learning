#include "normal.h"

template <typename elemType>
elemType* find(const elemType *first, const elemType *last,
               const elemType &value)
{
    if (!first || !last)
        return nullptr;
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return nullptr;
}
