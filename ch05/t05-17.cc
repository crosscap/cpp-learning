#include <iostream>
#include <vector>

using std::vector;



bool int_prefix(vector<int> &v1, vector<int> &v2)
{
    int min_size = v1.size() < v2.size() ? v1.size() : v2.size();
    for (int ix = 0; ix != min_size; ++ix)
        if (v1[ix] != v2[ix])
            return false;

    return true;
}
int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    std::cout << int_prefix(v1, v2) << std::endl;

    return 0;
}