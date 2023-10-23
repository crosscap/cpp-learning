#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    vector<int> counter(5, 0);
    char ch;

    while (std::cin >> ch) {
        if (ch == 'a' || ch == 'A')
            ++counter[0];
        else if (ch == 'e' || ch == 'E')
            ++counter[1];
        else if (ch == 'i' || ch == 'I')
            ++counter[2];
        else if (ch == 'o' || ch == 'O')
            ++counter[3];
        else if (ch == 'u' || ch == 'U')
            ++counter[4];
    }

    std::cout << "a: " << counter[0] << '\n'
              << "e: " << counter[1] << '\n'
              << "i: " << counter[2] << '\n'
              << "o: " << counter[3] << '\n'
              << "u: " << counter[4] << std::endl;

        return 0;
}