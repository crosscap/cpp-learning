#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

int main()
{
    int grade;
    string lettergrade;
    std::cin >> grade;

    if (grade < 0 || grade > 100)
        return -1;
    if (grade < 60)
        lettergrade = "F";
    else if (grade < 70)
        lettergrade = "D";
    else if (grade < 80)
        lettergrade = "C";
    else if (grade < 90)
        lettergrade = "B";
    else if (grade < 100)
        lettergrade = "A";
    else
        lettergrade = "A++";

    return 0;
}