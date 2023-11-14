#include <list>
#include <vector>

using std::list;
using std::vector;

list<int> li(10, 42);
vector<int> vi(10, 42);

vector<double> vd1(li.begin(), li.end());
vector<double> vd2(vi.begin(), vi.end());