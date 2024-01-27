#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

int main()
{
	map<string, vector<int>> msvi;
	msvi["a"].push_back(1);
	msvi["b"].push_back(2);
	map<string, vector<int>>::iterator ret = msvi.find("a");
}