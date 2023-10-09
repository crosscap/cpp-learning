#include <map>
#include <fstream>
#include "normal.h"

void get_names(ifstream &, map<string, vector<string>> &);
void user_search_name(const map<string, vector<string>> &);
int map_find(const map<string, vector<string>> &, const string);
void show_family(const map<string, vector<string>> &);

int main()
{
    map<string, vector<string>> families;

    ifstream in_f("families.txt");
    if (!in_f) {
        cerr << "!! unable to open input files.\n";
        return -1;
    }
    get_names(in_f, families);
    user_search_name(families);
    show_family(families);

    return 0;
}

void get_names(ifstream &infile, map<string, vector<string>> &families)
{
    string textline;

    while (getline(infile, textline)) {
        string fam_name;
        vector<string> child;
        string::size_type pos = 0, prev_pos = 0, text_size = textline.size();
        while ((pos = textline.find_first_of(' ', pos)) != string::npos) {
            string::size_type end_pos = pos - prev_pos;
            if (!prev_pos) {
                fam_name = textline.substr(prev_pos, end_pos);
            } else {
                child.push_back(textline.substr(prev_pos, end_pos));
            }
            prev_pos = ++pos;
        }
    if (fam_name.empty()) {
        fam_name = textline;
        prev_pos = text_size;
    }
    if (prev_pos < text_size)
        child.push_back(textline.substr(prev_pos, pos-prev_pos));
    if (!families.count(fam_name))
        families[fam_name] = child;
    else
        cerr << "Opps! We already have a "
             << fam_name << " in our map!" << endl;
    }
}

void user_search_name(const map<string, vector<string>>& families)
{
    bool going = false;
    string decide, search;
    while (!going) {
        cout << "Do you want search some names?(y/n)" << endl;
        cin >> decide;
        if (decide == "n" || decide == "N")
            going = true;
        else {
            cout << "enter what you want search:" << endl;
            cin >> search;
            map_find(families, search);
        }
    }
}

int map_find(const map<string, vector<string>>& families, const string find)
{
    int child_count = 0;
    map<string, vector<string>>::const_iterator im;
    if (!families.count(find)) {
        cout << find << " not exit!" << endl;
        return -1;
    } else {
        cout << "exit!\nthe child of " << find << " is " << endl;
        im = families.find(find);
        if (im->second.empty()) {
            cout << "don't have child!" << endl;
        } else {
            for (vector<string>::const_iterator is = im->second.begin();
                    is != im->second.end(); ++is) {
                cout << *is << ' ';
                ++child_count;
            }
        cout << endl;
        }

    }
    return child_count;
}

void show_family(const map<string, vector<string>>& families)
{
    if (families.empty()) {
        cout << "have no data!" << endl;
    } else {
        map<string, vector<string>>::const_iterator im;
        for (im = families.begin(); im != families.end(); ++im) {
            if (im->second.empty()) {
                cout << im->first << " has no child!" << endl;
            } else {
                cout << im->first << " has child: ";
                vector<string>::const_iterator is;
                for (is = im->second.begin(); is != im->second.end(); ++is) {
                    cout << *is << ' ';
                }
                cout << endl;
            }
        }
    }
}
