#include <cstring>
#include <functional>

using std::size_t;
using std::strcmp;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

template <size_t M, size_t N>
int compare(const char (&p1)[M], const char (&p2)[N])
{
	return strcmp(p1, p2);
}

template <>
int compare(const char *const &p1, const char *const &p2)
{
	return strcmp(p1, p2);
}

// template <typename T, typename F = std::less<T>>
// int compare(const T &v1, const T &v2, F f = F())
// {
// 	if (f(v1, v2)) return -1;
// 	if (f(v2, v1)) return 1;
// 	return 0;
// }