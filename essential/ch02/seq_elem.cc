#include <iostream>
#include <vector>
using namespace std;

inline bool is_size_ok(int size)
{
    const int max_size = 1024;
    if (size <= 0 || size > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}

inline const vector<int> *
fibon_seq(int size)
{
    static vector<int> elems;

    if (!is_size_ok(size))
        return 0;
    for (int ix = elems.size(); ix < size; ++ix) {
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }

    return &elems;
}

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = nullptr)
{
    const vector<int> *pseq = seq_ptr(pos);
    if (!seq_ptr) {
        cout << "Internal Error: seq_ptr is set to null!";
        return 0;
    } else if (!pseq) {
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}
