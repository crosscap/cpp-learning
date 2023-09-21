#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s, s_sum;

    while (cin >> s)
        s_sum += s;
    cout << s_sum << endl;

    while (cin >> s)
    {
        if (!s_sum.empty())
            s_sum += " ";
        s_sum += s;
    }
    cout << s_sum << endl;

    return 0;
}