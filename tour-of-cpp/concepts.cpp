#include <ranges>
#include <iterator>

template <typename B>
concept Boolean =
    requires(B x, B y) {
        {x = true};
        {x = false};
        {x = (x == y)};
        {x = (x != y)};
        {x = !x};
        {x = x = (x = y)};
    };

template <typename T>
concept Equality_comparable =
    requires(T a, T b) {
        { a == b } -> Boolean;
        { a != b } -> Boolean;
    };

template <typename T, typename U = T>
concept Number =
    requires(T x, U y) {
        x + y;
        x - y;
        x * y;
        x / y;
        x += y;
        x -= y;
        x *= y;
        x /= y;
        x = x;
        x = 0;
    };

template <typename T, typename U = T>
concept Arithmetic =
    Number<T, U> && Number<U, T>;

template <typename S>
concept Sequence = std::ranges::input_range<S>;

template <std::forward_iterator Iter, Arithmetic<std::iter_value_t<Iter>> Val>
Val accumulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p != last; ++p)
        res += *p;
    return res;
}
