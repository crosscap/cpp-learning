#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename elemType>
inline elemType* begin(const vector<elemType> &vec);
template <typename elemType>
inline elemType* end(const vector<elemType> &vec);
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last,
                  const elemType &value);
