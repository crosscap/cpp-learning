#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct PersonInfo;

bool valid(const string &);
std::string format(const string &);

int main()
{
    string line, word;
    vector<PersonInfo> people;
    std::fstream input("PersonInfo.txt");
    while (getline(input, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            std::cout << entry.name << " " << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << "invalid number(s) "
                      << badNums.str() << std::endl;
    }
}

struct PersonInfo {
    string name;
    vector<string> phones;
};