#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;

// void print(const int *ip); not fit to int
void print(const int *beg, const int *end);
void print(const int ca[], size_t size);

int main()
{
    int i = 0;
    int j[] = {0, 1};

    print(&i, &i + 1);
    print(begin(j), end(j));
    print(&i, 1);
    print(j, 2);

    return 0;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << ' ';
    cout << endl;
}

void print(const int ca[], size_t size)
{
    for (size_t ix = 0; ix != size; ++ix)
        cout << ca[ix] << ' ';
    cout << endl;
}