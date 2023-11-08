#include <iostream>
#include <string>

using std::cin;
using std::cout;

std::istream &read_until_EOF(std::istream &is);

int main()
{
    read_until_EOF(cin);
    return 0;
}