#include "Triangular.h"

int sum(const Triangular &trian)
{
    if (!trian.length())
        return 0;
    int val, sum = 0;
    trian.next_reset();
    while (trian.next(val))
        sum += val;

    return sum;
}