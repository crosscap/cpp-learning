#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    cout << "char:\t\t" << sizeof (char)<< endl;
    cout << "bool:\t\t" << sizeof (bool)<< endl;
    cout << "short:\t\t" << sizeof (short)<< endl;
    cout << "int:\t\t" << sizeof (int)<< endl;
    cout << "signed int:\t" << sizeof (signed int)<< endl;
    cout << "unsigned int:\t" << sizeof (unsigned int)<< endl;
    cout << "long:\t\t" << sizeof (long)<< endl;
    cout << "unsigned long:\t" << sizeof (unsigned long)<< endl;
    cout << "long long:\t" << sizeof (long long)<< endl;
    cout << "unsigned long long:\t" << sizeof (unsigned long long)<< endl;
    cout << "float:\t\t" << sizeof (float)<< endl;
    cout << "double:\t\t" << sizeof (double)<< endl;
    cout << "long double:\t" << sizeof (long double)<< endl;

    return 0;
}