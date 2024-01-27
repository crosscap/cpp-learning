#include <iostream>

int main()
{
    int val = 0, sum = 0;

    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << val << ' ' << sum << std::endl;

    sum = val = 0;
    while (sum += val++, val <= 10)
        ;
    std::cout << val << ' ' << sum << std::endl;

    return 0;
}