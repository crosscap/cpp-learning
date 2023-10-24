#include <iostream>

using std::cin;
using std::cout;

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
        cout << "\nfact of " << val << " is " << fact(val);
        cout << "\nWant more? Please enter y or n: ";
        cin >> ch;
    }
}