#include <type_traits>

using std::make_unsigned;

template <typename T1, typename T2>
auto sum(T1 elem1, T2 elem2) -> decltype(elem1 + elem2)
{
	return elem1 + elem2;
}