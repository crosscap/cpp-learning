#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using int_array_0 = int[4];
typedef int int_array_1[4];

int main()
{
    int ia[3][4];
    for (auto i = 0; i < 3; ++i)
        for (auto j = 0; j < 4; ++j)
            ia[i][j] = i * 4 + j;

    // version 1
    cout << "version 1" << endl;
    for (const int_array_0 &p : ia)
    {
        for (int q : p)
            cout << q << " ";
        cout << endl;
    }
    cout << endl;

    // version 1 other
    cout << "version 1 other" << endl;
    for (const int_array_1 &p : ia)
    {
        for (int q : p)
            cout << q << " ";
        cout << endl;
    }
    cout << endl;

    // version 2
    cout << "version 2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    
    // version 3
    cout << "version 3" << endl;
    for (const int_array_0 *p = ia; p < ia + 3; ++p)
    {
        for (const int *q = *p; q < *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    cout << endl;

    cout << "version 3 other" << endl;
    for (const int_array_1 *p = ia; p < ia + 3; ++p)
    {
        for (const int *q = *p; q < *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
