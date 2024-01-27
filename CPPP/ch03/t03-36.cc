#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int ia[10] = {}, ib[10] = {};
    int i;
    vector<int> v0(10, 0), v1(10, 0);

    ia[1] = 1;
    v0[1] = 2;

    for (i = 0; i != 10 && ia[i] == ib[i]; ++i)
        continue;
    if (i == 10)
        printf ("ia = ib\n");
    else
        printf ("ia != ib\n");
    if (v0 == v1)
        printf ("v0 = v1\n");
    else
        printf ("v0 != v1\n");

    return 0;
}