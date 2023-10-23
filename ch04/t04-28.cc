#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    cout << "char: " << sizeof (char)<< endl;
    cout << "bool: " << sizeof (bool)<< endl;
    cout << "short: " << sizeof (short)<< endl;
    cout << "int: " << sizeof (int)<< endl;
    cout << "signed int: " << sizeof (signed int)<< endl;
    cout << "unsigned int: " << sizeof (unsigned int)<< endl;
    cout << "long: " << sizeof (long)<< endl;
    cout << "unsigned long: " << sizeof (unsigned long)<< endl;
    cout << "long long: " << sizeof (long long)<< endl;
    cout << "unsigned long long: " << sizeof (unsigned long long)<< endl;
    cout << "float: " << sizeof (float)<< endl;
    cout << "double: " << sizeof (double)<< endl;
    cout << "long double: " << sizeof (long double)<< endl;

    return 0;
}