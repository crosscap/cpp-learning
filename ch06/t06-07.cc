#include <iostream>

using std::cin;
using std::cout;

int function_flag()
{
    static int flag = 0;

    return flag++;
}

int main()
{
    cout << function_flag() << ' ' << function_flag() << std::endl;
    return 0;
}