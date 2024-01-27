#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct PersonInfo;

int main()
{
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    while (getline(std::cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
}

struct PersonInfo {
    string name;
    vector<string> phones;
};