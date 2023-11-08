#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;

std::istream &read_until_EOF(std::istream &is);

int main()
{
    std::string str("go to the shop");
    std::istringstream sstr(str);

    read_until_EOF(sstr);
    printf("\n");
    return 0;
}

std::istream &read_until_EOF(std::istream &is)
{
    std::string line;

    do {
        getline(is, line);
        if (is.bad()) {
            std::cerr << "wrong in stream." << std::endl;
            return is;
        }
        if (is.fail()) {
            std::cerr << "final in data, try again: " << std::endl;
            is.clear();
            continue;
        }
        cout << line;
    } while (!is.eof());
    is.clear();

    return is;
}