#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::string;

bool str_have_upper(const string& str)
{
    string::size_type index;
    bool flag = false;

    for (index = 0; index != str.size(); ++index)
        if (isupper(str[index])) {
            flag = true;
            break;
        }

    return flag;
}

void str_to_lower(string& str)
{
    string::size_type index;
    bool flag = false;

    for (index = 0; index != str.size(); ++index)
        str[index] = tolower(str[index]);
}

int main()
{
    string str("go To Then nord.");

    cout << "str have upper " << str_have_upper(str) << std::endl;
    str_to_lower(str);
    cout << str << std::endl;

    return 0;
}