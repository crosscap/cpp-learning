#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename elemType>
elemType my_max(elemType a, elemType b)
{
    return a < b ? b : a;
}

template <typename elemType>
elemType my_max(vector<elemType> a)
{
    elemType max_elem = a[0];
    for (auto index = a.begin(); index != a.end(); ++index)
        if (*index > max_elem)
            max_elem = *index;
    return max_elem;
}

template <typename elemType>
elemType my_max(elemType a[], int size)
{
    elemType max = a[0];
    for (int i = 0; i < size; ++i) {
        max = max > a[i] ? max : a[i];
    }
    return max;
}

int main()
{
    vector<int> ai = {2, 4, 5};
    vector<float> af = {2.4, 5.3, 2.1};
    vector<string> as = {"gogogo", "runrunrun", "push"};
    int ari[] = {2, 4, 5};
    float arf[] = {2.4, 5.3, 2.1};
    string ars[] = {"gogogo", "runrunrun", "push"};

    cout << my_max(3, 5) << endl;
    cout << my_max(2.1, 4.7) << endl;
    cout << my_max("gogogo", "runrunrun") << endl;
    cout << my_max(ai) << endl;
    cout << my_max(af) << endl;
    cout << my_max(as) << endl;
    cout << my_max(ari, 2) << endl;
    cout << my_max(arf, 2) << endl;
    cout << my_max(ars, 2) << endl;

    return 0;
}