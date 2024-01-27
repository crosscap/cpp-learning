#include <iostream>
#include <vector>

using std::vector;

void show_vector_re(const vector<int> &vi, int length)
{
    if (length > 0)
        show_vector_re(vi, length - 1);
    std::cout << vi[length] << ' ';
    return;
}