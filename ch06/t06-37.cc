#include <string>

using std::string;
typedef string arr[10];
using arr2 = string[10];

string array[10];

string (&function())[10];

arr &function(int);
arr2 &function(int, int);
auto function(int, int, int) -> string(&)[10];
decltype(array) &function(int, int, int, int);