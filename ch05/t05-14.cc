#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    string str, prestr;
    string max_str;
    int max_counter = 0;
    int now_counter = 0;

    while(std::cin >> str) {
        if (str == prestr) {
            ++now_counter;
        } else {
            ++now_counter;
            if (now_counter > max_counter) {
                max_counter = now_counter;
                max_str = prestr;
            }
            prestr = str;
            now_counter = 0;
        }
        // std::cout << max_counter << ' ' << prestr << ' ' << str << std::endl;
    }
    if (now_counter + 1 > max_counter) {
                max_counter = now_counter;
                max_str = prestr;
            }
    if (max_str.size() == 0)
        std::cout << "not exist such string" << '\n';
    else
        std::cout << max_str << ' ' << max_counter << '\n';
}