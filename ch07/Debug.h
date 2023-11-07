class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b), count(0) {}
    constexpr Debug(bool b, bool i, bool o)
        : hw(b), io(i), other(o), count(0) {}
    constexpr Debug(bool b, bool i, bool o, int cnt)
        : hw(b), io(i), other(o), count(cnt) {}

    constexpr bool any() { return hw || io || other; }
    int get_count() { return count; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
    void set_count(int cnt) { count = cnt; }

private:
    bool hw;
    bool io;
    bool other;
    int count = 0;
};