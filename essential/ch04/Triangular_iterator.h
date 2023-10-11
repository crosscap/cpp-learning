#include <string>
#include <iostream>
using namespace std;

class Triangular_iterator
{
public:
    Triangular_iterator(int index) : _index(index-1) { }
    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator &operator++(); // prefix
    Triangular_iterator operator++(int); // postfix

private:
    void check_integrity () const;
    int _index;
};