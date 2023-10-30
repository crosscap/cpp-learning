#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    for (int ix = 1; ix != argc; ++ix) {
        char *cp = argv[ix];
        while (*cp)
            cout << *cp++;
        cout << ' ';
    }
    cout << endl;

    return 0;
}