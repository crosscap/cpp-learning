#include <vector>

using std::vector;

int function(int, int);

using pf = int (*)(int, int);

vector<decltype(function)*> vf1;
vector<decltype((function))> vf2;
vector<int (*)(int, int)> vf3;

int function(int ia, int ib)
{
    return ia + ib;
}