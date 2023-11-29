#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

void add_new_family(map<string, vector<pair<string, string>>> &family, const string fam_name, const vector<pair<string, string>> childs)
{
	family[fam_name] = childs;
}

void add_new_child(map<string, vector<pair<string, string>>> &family, const string fam_name, const pair<string, string> new_child)
{
	family[fam_name].push_back(new_child);
}