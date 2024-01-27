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
    while (getline(std::cin, line)) {
        PersonInfo info;
        std::istringstream record(line);
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