#include <iostream>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::exception;

int main()
{
    int i1, i2;

    cin >> i1 >> i2;
    if (i2 == 0)
            throw exception();
        cout << '\n' << (i1 / i2) << endl;

    return 0;
}