#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

void line_to_vector();

int main()
{
    line_to_vector();
    return 0;
}

void line_to_vector()
{
    std::string word;
    std::string line;
    std::vector<std::string> vs;
    std::ifstream ifs("input.txt");
    if (ifs)
        while (getline(ifs, line))
            vs.push_back(line);
    ifs.close();

    std::istringstream istrs;
    for (auto &r : vs) {
        istrs.clear();
        istrs.str(r);
        while (istrs >> word) {
            cout << word << std::endl;
        }
    }
}