#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    string str;
    vector<string> strings0, strings1;
    while (std::cin >> str)
        strings0.push_back(str);
    for (; std::cin >> str; )
        strings1.push_back(str);

    int index = 0;
    while (index != strings0.size()) {
        std::cout << strings0[index++];
    }
    std::cout << std::endl;
    for (int ix = 0; ix != strings1.size(); ++ix)
        std:: cout << strings1[ix];
    std::cout << std::endl;

}