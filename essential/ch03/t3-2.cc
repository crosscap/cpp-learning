#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include "normal.h"

void process_file(ifstream &, vector<string> &, const set<string> &);
void display_word_count(const vector<string> &);
bool string_shouter(string, string);
int main()
{
    set<string> word_exclusion{"a", "an", "or", "of", "the", "and", "but"};
    vector<string> text;
    ifstream in_file(".//input_file.txt");
    if (!in_file) {
        cerr << "!! unable to open input files.\n";
        return -1;
    }
    process_file(in_file, text, word_exclusion);
    sort(text.begin(), text.end(), string_shouter);
    display_word_count(text);

    return 0;
}

void process_file(ifstream &in, vector<string> &words, const set<string> &we)
{
    string word;
    while (in >> word) {
        if (we.count(word))
            continue;
        else {
            words.push_back(word);
        }
    }
}

void display_word_count(const vector<string> &words)
{
    vector<string>::const_iterator ip;
    for (ip = words.begin(); ip != words.end(); ++ip) {
        cout << *ip << endl;
    }
}

bool string_shouter(string s1, string s2)
{
    return s1.length() < s2.length() ? true : false;
}