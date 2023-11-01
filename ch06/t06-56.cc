#include <iostream>
#include <vector>

using std::vector;

int add(int, int);
int sub(int, int);
int mul(int, int);
int mydiv(int, int);

int main()
{
    int ia = 8, ib = 2;
    vector<int (*)(int, int)> vf{add, sub, mul, mydiv};

    std::cout << "add: " << vf[0](ia, ib) << std::endl;
    std::cout << "sub: " << vf[1](ia, ib) << std::endl;
    std::cout << "mul: " << vf[2](ia, ib) << std::endl;
    std::cout << "div: " << vf[3](ia, ib) << std::endl;

    return 0;
}

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
