#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename InputIterator, typename OutputIterator,
          typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
       OutputIterator at, const ElemType &val, Comp pred);

int main()
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2(elem_size);

    cout << "filtering integer array for values less than 8\n";
    filter(ia, ia+elem_size, ia2, elem_size, less<int>());
    cout << "filtering integer vector for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());
}

template <typename InputIterator, typename OutputIterator,
          typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
       OutputIterator at, const ElemType &val, Comp pred)
{
    while ((first =
            find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "find value: " << *first << endl;
        *at++ = *first++;
    }

    return at;
}