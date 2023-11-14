#include <vector>

using std::vector;

vector<int> vi1;
vector<int> vi2(10);
vector<int> vi3(10, 42);
vector<int> vi4{10, 42};
vector<int> vi5(vi3);
vector<int> vi6(vi3.begin(), vi3.end());