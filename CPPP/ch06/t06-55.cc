#include <vector>

using std::vector;

int add(int, int);
int sub(int, int);
int mul(int, int);
int mydiv(int, int);

vector<int (*)(int, int)> vf{add, sub, mul, mydiv};

inline int add(int ia, int ib)
{
    return ia + ib;
}

inline int sub(int ia, int ib)
{
    return ia - ib;
}

inline int mul(int ia, int ib)
{
    return ia * ib;
}

inline int mydiv(int ia, int ib)
{
    return ia / ib;
}
