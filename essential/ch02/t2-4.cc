#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool size_ok(int pos)
{
    const int max_size = 1024;
    if (pos <= 0 || pos > max_size) {
        cerr << "pent_seq(): oops: invalid size: "
             << pos << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}

const vector<int>* pent_seq(int size)
{
    static vector<int> elem;
    if (!size_ok(size)) {
        return nullptr;
    } else {
        for (int ix = elem.size(); ix < size; ++ix) {
            int n = ix + 1;
            elem.push_back(n * (3 * n - 1) / 2);
        }
    }
    return &elem;
}

int seq_elem(const int pos, const vector<int> *elem)
{
    elem = pent_seq(pos);
    return (*elem)[pos-1];
}

template <typename elemType>
void show_vector(const vector<elemType> &elem, const string &v_type)
{
    // cout << "The type in vector is " << v_type << '.' << endl;
    for (int ix = 0; ix < elem.size(); ++ix) {
        cout << elem[ix] << ' ';
    }
    cout << endl;
}

int main()
{
    const vector<int> *elem;
    elem = pent_seq(6);
    cout << elem << endl;
    show_vector(*elem, "int");
    int i = seq_elem(10, elem);
    cout << i << endl;
    show_vector(*elem, "int");
    i = seq_elem(4, elem);
    cout << i << endl;
    show_vector(*elem, "int");
    return 0;
}
