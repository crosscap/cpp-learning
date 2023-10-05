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
    vector<int> maxi, ai = {2, 4, 5}, bi = {9 ,2};
    vector<float> maxf, af = {2.4, 5.3, 2.1}, bf = {9.3, 7.2, 4.2, 5.1};
    vector<string> maxs;
    vector<string> as = {"gogogo", "runrunrun", "push"};
    vector<string> bs = {"go", "run"};
    int ari[] = {2, 4, 5};
    float arf[] = {2.4, 5.3, 2.1};
    string ars[] = {"gogogo", "runrunrun", "push"};

    cout << my_max(3, 5) << endl;
    cout << my_max(2.1, 4.7) << endl;
    cout << my_max("gogogo", "runrunrun") << endl;
    maxi = my_max(ai, bi);
    for (int i = 0; i < maxi.size(); ++i)
        cout << maxi[i] << (i == maxi.size() - 1 ? '\n' : ' ');
    maxf = my_max(af, bf);
    for (int i = 0; i < maxf.size(); ++i)
        cout << maxf[i] << (i == maxf.size() - 1 ? '\n' : ' ');
    maxs = my_max(as, bs);
    for (int i = 0; i < maxs.size(); ++i)
        cout << maxs[i] << (i == maxs.size() - 1 ? '\n' : ' ');
    cout << my_max(ari, 3) << endl;
    cout << my_max(arf, 3) << endl;
    cout << my_max(ars, 3) << endl;

    return 0;
}