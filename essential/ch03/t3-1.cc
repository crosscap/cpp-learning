#include <map>
#include <set>
#include <fstream>
#include "normal.h"

void process_file(ifstream &, map<string,int> &, const set<string> &);
void user_search(map<string, int> &);
void display_word_count(const map<string,int> &);
int main()
{
    set<string> word_exclusion{"a", "an", "or", "of", "the", "and", "but"};
    map<string,int> text;
    ifstream in_file(".//input_file.txt");
    if (!in_file) {
        cerr << "!! unable to open input files.\n";
        return -1;
    }
    process_file(in_file, text, word_exclusion);
    user_search(text);
    display_word_count(text);

    return 0;
}

void process_file(ifstream &in, map<string,int> &words, const set<string> &we)
{
    string word;
    while (in >> word) {
        if (we.count(word))
            continue;
        else {
            words[word]++;
        }
    }
}

void user_search(map<string, int> &words)
{
    bool going = false;
    string decide, search;
    while (!going) {
        cout << "Do you want search some words?(y/n)" << endl;
        cin >> decide;
        if (decide == "n" || decide == "N")
            going = true;
        else {
            cout << "enter what you want search:" << endl;
            cin >> search;
            if (words.count(search)) {
                cout << "exit! the number of " << search
                     << " is " << words[search] << '.' << endl;
            } else {
                cout << search << " not exit!" << endl;
            }
        }
    }
}

void display_word_count(const map<string,int> &words)
{
    map<string,int>::const_iterator ip;
    for (ip = words.begin(); ip != words.end(); ++ip) {
        cout << ip->first << ' ' << ip->second << endl;
    }
}