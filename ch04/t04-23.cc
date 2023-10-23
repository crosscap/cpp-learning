#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

string s = "word";
// string pl = s + s[s.size() - 1] == 's' ? "" : "s";
// 上式的等价写法
// string pl = (s + s[s.size() - 1]) == 's' ? "" : "s";
// 修改后：
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");