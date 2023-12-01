#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::multimap;
using std::string;
using std::vector;

void add_new_child(multimap<string, string> &family, const string &fam_name, const string &new_child)
{
	family.insert({fam_name, new_child});
}