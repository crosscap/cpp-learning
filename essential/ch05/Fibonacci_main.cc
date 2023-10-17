#include "Fibonacci.h"

int main()
{
    Fibonacci fib;
    cout << "fib: beginning at element 1 for 1 element: " << fib << endl;

    Fibonacci fib2(16);
    cout << "fib: beginning at element 1 for 16 element: " << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib: beginning at element 12 for 8 element: " << fib3 << endl;

    return 0;
}