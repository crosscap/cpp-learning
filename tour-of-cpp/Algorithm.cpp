#include <vector>

template <typename Sequence, typename Value>
Value sum(const Sequence& seq, Value init)
{
    for (const auto& elem : seq) {
        init += elem;
    }
    return init;
}

template <typename T>
class Less_than
{
    const T val;

public:
    Less_than(const T& v)
        : val{v} { }
    bool operator()(const T& x) const { return x < val; }
};

template <typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c) {
        if (pred(x)) {
            ++cnt;
        }
    }
    return cnt;
}

template <typename C, typename Oper>
void for_each(C& c, Oper op)
{
    for (auto& x : c) {
        op(x);
    }
}

template <class S>
void rotate_and_draw(std::vector<S>& v)
{
    for_each(v, [](auto& s) { s->rotate(); s->draw(); });
}
