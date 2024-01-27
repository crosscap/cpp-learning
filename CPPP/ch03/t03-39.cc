#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char sa[10] = "hello", sb[10] = "hell";
    int i;
    string s0{"hello"}, s1{"hello"};

    for (i = 0; i != 10 && sa[i] != '\0' && sa[i] == sb[i]; ++i)
        continue;
    if ((sa[i] == '\0' && sb[i] == '\0') || i == 10)
        printf ("sa = sb\n");
    else
        printf ("sa != sb\n");
    if (s0 == s1)
        printf ("s0 = s1\n");
    else
        printf ("s0 != s1\n");

    return 0;
}