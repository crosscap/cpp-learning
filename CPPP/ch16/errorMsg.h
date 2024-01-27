#include <algorithm>
#include <iostream>

#include "debug_rep.h"

using std::begin;
using std::end;
using std::endl;
using std::cout;
using std::ostream;

template <typename T>
ostream &print(ostream &, const T &);
template <typename T, typename... Args>
ostream &print(ostream &, const T &, const Args & ...);
template <typename... Args>
ostream &errorMsg(ostream &, const Args & ...);

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args & ... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args & ... rest)
{
	return print(os, debug_rep(rest)...);
}