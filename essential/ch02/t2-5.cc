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

vector<int> max(vector<int> a, vector<int> b)
{
    return a < b ? b : a;
}

vector<float> max(vector<float> a, vector<float> b)
{
    return a < b ? b : a;
}

vector<string> max(vector<string> a, vector<string> b)
{
    return a < b ? b : a;
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
    vector<int> maxi, ai = {2, 4, 5}, bi = {9 ,2};
    vector<float> maxf, af = {2.4, 5.3, 2.1}, bf = {9.3, 7.2, 4.2, 5.1};
    vector<string> maxs;
    vector<string> as = {"gogogo", "runrunrun", "push"};
    vector<string> bs = {"go", "run"};
    int ari[] = {2, 4, 5};
    float arf[] = {2.4, 5.3, 2.1};
    string ars[] = {"gogogo", "runrunrun", "push"};

    cout << max(3, 5) << endl;
    cout << max(2.1, 4.7) << endl;
    cout << max("gogogo", "runrunrun") << endl;
    maxi = max(ai, bi);
    for (int i = 0; i < maxi.size(); ++i)
        cout << maxi[i] << (i == maxi.size() - 1 ? '\n' : ' ');
    maxf = max(af, bf);
    for (int i = 0; i < maxf.size(); ++i)
        cout << maxf[i] << (i == maxf.size() - 1 ? '\n' : ' ');
    maxs = max(as, bs);
    for (int i = 0; i < maxs.size(); ++i)
        cout << maxs[i] << (i == maxs.size() - 1 ? '\n' : ' ');
    cout << max(ari, 3) << endl;
    cout << max(arf, 3) << endl;
    cout << max(ars, 3) << endl;

    return 0;
}