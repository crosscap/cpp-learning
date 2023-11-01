#include <iostream>

using std::cout;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}

void f()
{
    cout << "called function:f()" << std::endl;
}

void f(int i)
{
    cout << "called function: f(int)" << std::endl;
}

void f(int ia, int ib)
{
    cout << "called function: f(int, int)" << std::endl;
}

void f(double da, double db)
{
    cout << "called function: f(double, double)" << std::endl;
}