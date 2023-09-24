#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[10];
    int *ip = ia;

    for (int i = 0; i < 10; ++i)
        ia[i] = i;
    while (ip != std::end(ia))
    {
        *ip = 0;
        ++ip;
    }
    ip = ia;
    while (ip != std::end(ia))
        printf ("%d ", *(ip++));
    cout << endl;

    return 0;
}
