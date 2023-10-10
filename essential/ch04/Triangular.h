#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Triangular {
public:
    Triangular(int len = 1, int bp = 1);
    int length() const {return _length;}
    int beg_pos() const {return _beg_pos;}
    int elem(int pos) const;

    bool next(int &val) const;
    void next_reset() const {_next = _beg_pos - 1;}
    Triangular& copy(const Triangular &rhs);

    static bool is_elem(int value);
    static void gen_elements(int);
    static void gen_elems_to_value(int);
    static void display(int length, int beg_pos, ostream &os = cout);
private:
    int _length;
    int _beg_pos;
    mutable int _next;
    static vector<int> _elems;
    static const int _max_elems = 1024;
};
