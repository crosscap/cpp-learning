#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> text;

    for (auto it = text.begin(); 
        it != text.end() && !it->empty();
        ++it)
    {
        for (auto c = it->begin(); c != it->end(); ++c)
        {
            *c = toupper(*c);
            cout << *c;
        }
    }
    cout << endl;

    return 0;
}