#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    string out;

    for (int ix = 1; ix != argc; ++ix) {
        char *cp = argv[ix];
        while (*cp)
            out.push_back(*cp++);
    }
    cout << out << endl;

    return 0;
}