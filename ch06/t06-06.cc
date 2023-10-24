#include <iostream>

using std::cin;
using std::cout;

int counter(int val)
{
    int looper = 0;
    static int counter = 0;

    cout << "function was called " << ++counter << " times\n";
    while (looper < val) {
        cout << "in loop time: " << looper++ << '\n';
    }

    return counter;
}

int main()
{
    counter(5);
    counter(7);
    counter(1);

    return 0;
}