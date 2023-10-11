#include <string>
using namespace std;

class Triangular1
{
public:
    Triangular1(int len = 1, int bp = 1);

private:
    string _name;
    int _length;
    int _beg_pos;
    int _next;
};
