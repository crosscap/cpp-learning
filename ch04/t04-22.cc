#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
    int grade;
    cin >> grade;
    string finalgrade =
        (grade < 60 ) ? "fail"
                      : (grade < 75) ? "low pass"
                      : (grade < 90) ? "pass" : "high pass";
    cout << finalgrade << std::endl;

    string finalgrade_1;
    if (grade < 60)
        finalgrade_1 = "fail";
    else if (grade < 75)
        finalgrade_1 = "low pass";
    else if (grade < 90)
        finalgrade_1 = "pass";
    else
        finalgrade_1 = "high pass";
    cout << finalgrade_1 << std::endl;

    return 0;
}
