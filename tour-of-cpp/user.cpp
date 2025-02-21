#include "Vector.h"
#include <cmath>

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
    {
        sum += std::sqrt(v[i]);
    }
    return sum;
}

int main()
{
    Vector v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    double result = sqrt_sum(v);
    return 0;
}
