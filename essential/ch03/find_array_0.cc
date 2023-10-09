#include "normal.h"

template <typename elemType>
elemType* find(const elemType *array, int size,
               const elemType &value)
{
    if (!array || size < 1)
        return nullptr;
    for (int ix = 0; ix < size; ++ix)
        if (array[ix] == value)
            return &array[ix];
    return nullptr;
}
