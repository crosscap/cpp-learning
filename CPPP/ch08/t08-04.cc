#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

void line_to_vector()
{
    std::string line;
    std::vector<std::string> vs;
    std::ifstream ifs("input.txt");

    if (ifs)
        while (getline(ifs, line))
            vs.push_back(line);
    ifs.close();
    return;
}