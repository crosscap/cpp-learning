#include "Fibonacci.h"

inline void display(ostream &os, const num_sequence &ns, int pos);

int main()
{
    const int pos = 8;

    Fibonacci fib, fib1(8);
    display(cout, fib, pos);
    cout << "fib: " << fib1 << endl;

    return 0;
}

inline void display(ostream &os, const num_sequence &ns, int pos)
{
    os << "The element at position " << pos << " for the "
       << ns.what_am_i() << " sequence is " << ns.elem(pos) << endl;
}