#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::vector;

int main()
{
    string str, prestr;
    bool flag = false;

    while(std::cin >> str) {
        if (str == prestr) {
            if (!isupper(str[0]))
                continue;
            else {
                flag = true;
                break;
            }
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