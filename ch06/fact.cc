#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::cin;

int fact(int val)
{
    int answer = 1;
    for (int ix = 1; ix <= val; ++ix)
        answer *= ix;

    return answer;
}

void action_fact()
{
    char ch = 'y';
    while (ch != 'n' && ch != 'N') {
        int val;
        cout << "Please enter a number: ";
        cin >> val;
        cout << "fact of " << val << " is " << fact(val);
        cout << "\nWant more? Please enter y or n: ";
        cin >> ch;
    }
}