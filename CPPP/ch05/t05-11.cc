#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    vector<int> counter(8, 0);
    char ch;

    while (std::cin.get(ch)) {
        switch(ch) {
        case 'a':
        case 'A':
            ++counter[0];
            break;
        case 'e':
        case 'E':
            ++counter[1];
            break;
        case 'i':
        case 'I':
            ++counter[2];
            break;
        case 'o':
        case 'O':
            ++counter[3];
            break;
        case 'u':
        case 'U':
            ++counter[4];
            break;
        case ' ':
            ++counter[5];
            break;
        case '\n':
            ++counter[6];
            break;
        case '\t':
            ++counter[7];
            break;
        default:
            break;
    }

    std::cout << "a: " << counter[0] << '\n'
              << "e: " << counter[1] << '\n'
              << "i: " << counter[2] << '\n'
              << "o: " << counter[3] << '\n'
              << "u: " << counter[4] << '\n'
              << "\' \': " << counter[5] << '\n'
              << "\\n: " << counter[6] << '\n'
              << "\\t: " << counter[7] << std::endl;

        return 0;
}