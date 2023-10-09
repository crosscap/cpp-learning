#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a < b ? b : a;
}

float max(float a, float b)
{
    return a < b ? b : a;
}

string max(string a, string b)
{
    return a < b ? b : a;
}

int max(vector<int> a)
{
    int imax = a[0];
    for (auto index = a.begin(); index != a.end(); ++index)
        if (*index > imax)
            imax = *index;
    return imax;
}

float max(vector<float> a)
{
    float fmax = a[0];
    for (auto index = a.begin(); index != a.end(); ++index)
        if (*index > fmax)
            fmax = *index;
    return fmax;
}

string max(vector<string> a)
{
    string smax = a[0];
    for (auto index = a.begin(); index != a.end(); ++index)
        if (*index > smax)
            smax = *index;
    return smax;
}

int max(int a[], int size)
{
    int max = a[0];
    for (int i = 0; i < size; ++i) {
        max = max > a[i] ? max : a[i];
    }
    return max;
}

float max(float a[], int size)
{
    float max = a[0];
    for (int i = 0; i < size; ++i) {
        max = max > a[i] ? max : a[i];
    }
    return max;
}

string max(string a[], int size)
{
    string max = a[0];
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

    cout << max(3, 5) << endl;
    cout << max(2.1, 4.7) << endl;
    cout << max("gogogo", "runrunrun") << endl;
    cout << max(ai) << endl;
    cout << max(af) << endl;
    cout << max(as) << endl;
    cout << max(ari, 2) << endl;
    cout << max(arf, 2) << endl;
    cout << max(ars, 2) << endl;

    return 0;
}