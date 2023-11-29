#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

void add_new_family(map<string, vector<string>> &family, const string &fam_name, const vector<string> &childs)
{
	family[fam_name] = childs;
}

void add_new_child(map<string, vector<string>> &family, const string fam_name, const string new_child)
{
	family[fam_name].push_back(new_child);
}