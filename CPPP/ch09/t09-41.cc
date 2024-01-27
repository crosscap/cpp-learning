#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

string init_str_vc(vector<char> vc)
{
    const char *cp = &vc[0];
    string str(cp, vc.size());

    return str;
}

int main()
{
    vector<char> vc = {'h', 'e', 'l', 'l', 'o'};
    string str = init_str_vc(vc);

    std::cout << str << std::endl;

    return 0;
}