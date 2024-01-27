#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<int> counter(8, 0);
    vector<int> fcounter(3, 0);
    bool f_flag = false;
    char ch;

    while (std::cin.get(ch)) {
        switch (ch) {
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
        case 'f':
        case 'F':
            f_flag = true;
            break;
        default:
            break;
        }
        if (f_flag) {
            switch (ch) {
            case 'f':
            case 'F':
                ++fcounter[0];
                break;
            case 'l':
            case 'L':
                ++fcounter[1];
                break;
            case 'i':
            case 'I':
                ++fcounter[2];
                break;
            }
            f_flag = false;
        }
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