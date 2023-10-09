#include <list>
#include "normal.h"

int main()
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *ipa = find(ia, ia+asize, 1024);
    if (ipa != ia+asize)
        cout <<"find array" << endl;
    ipa = find(ia, ia+asize, 21);
    if (ipa != ia+asize)
        cout <<"find array" << endl;

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 1024);
    if (it != ivec.end())
        cout <<"find vector" << endl;
    it = find(ivec.begin(), ivec.end(), 21);
    if (it != ivec.end())
        cout <<"find vector" << endl;

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 1024);
    if (iter != ilist.end())
        cout <<"find list" << endl;
    iter = find(ilist.begin(), ilist.end(), 21);
    if (iter != ilist.end())
        cout <<"find list" << endl;

    return 0;
}

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last,
                  const elemType &value)
{
    for (; first != last; ++first)
        if (*first == value)
            return first;
    return last;
}

template <typename elemType>
inline elemType* begin(const vector<elemType> &vec)
{
    return vec.empty() ? nullptr : &vec[0];
}

template <typename elemType>
inline elemType* end(const vector<elemType> &vec)
{
    return vec.empty() ? nullptr : &vec[vec.size()];
}