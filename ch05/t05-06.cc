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
    if (grade >= 60 && grade < 70)
        lettergrade = "D";
    if (grade >= 70 &&grade < 80)
        lettergrade = "C";
    if (grade >= 80 &&grade < 90)
        lettergrade = "B";
    if (grade >= 90 &&grade < 100)
        lettergrade = "A";
    if (grade == 100)
        lettergrade = "A++";

    return 0;
}