#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream in_file(".\\integers.txt");
    ofstream odd_file(".\\int_odd.txt");
    ofstream even_file(".\\int_even.txt");
    if (!in_file || !odd_file || !even_file) {
        cerr << "!! unable to open the necessary files.\n";
        return -1;
    }
    istream_iterator<int> is(in_file);
    istream_iterator<int> eof;
    ostream_iterator<int> os_odd(odd_file, " ");
    ostream_iterator<int> os_even(even_file, "\n");
    vector<int> integer, odd, even;

    copy(is, eof, back_inserter(integer));
    for (vector<int>::iterator iter = integer.begin(); 
            iter != integer.end(); ++iter) {
        if (*iter % 2) {
            odd.push_back(*iter);
        } else {
            even.push_back(*iter);
        }
    }
    copy(odd.begin(), odd.end(), os_odd);
    copy(even.begin(), even.end(), os_even);

    return 0;
}