#include "Triangular.h"

int sum(const Triangular &trian)
{
    int beg_pos = trian.beg_pos();
    int length = trian.length();
    int sum = 0;
    for (int ix = 0; ix < length; ++ix) {
        sum += trian.elem(beg_pos+ix);
    }
    return sum;
}