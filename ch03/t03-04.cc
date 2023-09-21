#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (s1 == s2)
        ;
    else if (s1 > s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;

    if (s1.size() == s2.size())
        ;
    else if (s1.size() > s2.size())
        cout << s1 << endl;
    else
        cout << s2 << endl;

    return 0;
}
