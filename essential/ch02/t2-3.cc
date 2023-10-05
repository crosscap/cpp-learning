#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool size_ok(int pos)
{
    const int max_size = 1024;
    if (pos <= 0 || pos > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
             << pos << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}

bool pent_seq(int size, vector<int> &elem)
{
    if (!size_ok(size)) {
        return false;
    } else if (size <= elem.size()) {
        cout << "smaller than exated seq.\nFinished." << endl;
    } else {
        for (int ix = elem.size(); ix < size; ++ix) {
            int n = ix + 1;
            elem.push_back(n * (3 * n - 1) / 2);
        }
        cout << "computing ok.\nFinished." << endl;
    }
    return true;
}

template <typename elemType>
void show_vector(const vector<elemType> &elem, const string &v_type)
{
    cout << "The type in vector is " << v_type << '.' << endl;
    for (int ix = 0; ix < elem.size(); ++ix) {
        cout << elem[ix] << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> elem;
    pent_seq(20, elem);
    show_vector(elem, "int");
    return 0;
}
