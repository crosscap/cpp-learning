class NoDefault
{
public:
    NoDefault(int inp) : num(inp) {}

private:
    int num;
};

class C
{
public:
    C(int i = 0) : No(i) {}

private:
    NoDefault No;
};