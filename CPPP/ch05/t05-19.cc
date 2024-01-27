#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    string s1, s2;
    string flag;

    do {
        std::cout << "please enter tow string: ";
        std::cin >> s1 >> s2;
        std::cout << "\nthe shorter one is: "
                  << (s1.length() < s2.length() ? s1 : s2) << std::endl;
        std::cout << "\nWant more? Please enter yes or no: ";
        std::cin >> flag;
    } while (!flag.empty() && flag[0] != 'n');

    return 0;
}