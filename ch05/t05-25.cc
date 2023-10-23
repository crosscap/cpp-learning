#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int i1, i2;
    std::string flag;

    while (cin >> i1 >> i2) {
        try {
            if (i2 == 0)
                throw runtime_error("div zero wrong");
            cout << '\n'
                 << (i1 / i2) << endl;
        } catch (runtime_error err) {
            std::cerr << err.what() << endl;
            std::cout << "\nWant more? Please enter yes or no: ";
            std::cin >> flag;
            if (flag.empty() || flag[0] == 'n')
                break;
        }
    }
    return 0;
}