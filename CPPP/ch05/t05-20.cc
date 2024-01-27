#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    string str, prestr;
    bool flag = false;

    while(std::cin >> str) {
        if (str == prestr) {
            flag = true;
            break;
        } else {
            prestr = str;
        }
        // std::cout << max_counter << ' ' << prestr << ' ' << str << std::endl;
    }
    if (!flag)
        std::cout << "not exist such string" << '\n';
    else
        std::cout << str << '\n';

    return 0;
}