#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
public:
    virtual ~Stack() { }

    bool pop(string &);
    bool push(const string &);
    bool peek(string &) const;

    int size() const { return _stack.size(); }
    bool empty() const { return _stack.empty(); }
    bool full() const { return _stack.size() == _stack.max_size(); }

    void print(ostream & = cout) const;

protected:
    vector<string> _stack;
};

class LIFO_Stack : public Stack
{
protected:
    LIFO_Stack() { }
};

class Peekback_Stack : public Stack
{
public:
    bool peekback(string &, int) const;

protected:
    Peekback_Stack() { }

    bool check_index(int) const;
};

bool Stack::pop(string &elem)
{
    if (empty()) {
        return false;
    } else {
        elem = _stack.back();
        _stack.pop_back();
        return true;
    }
}

bool Stack::push(const string &elem)
{
    if (full())
        return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::peek(string &elem) const
{
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}

void Stack::print(ostream &os = cout) const
{
    int length = size();
    if (length == 0)
        os << "empty stack!" << endl;
    else {
        os << "stack elems:\n";
        for (int ix = length - 1; ix >= 0; --ix)
            os << _stack[ix] << (ix == length -1 ? ' ' : '\n');
    }
}

ostream &operator<<(ostream &os, Stack &rhs)
{
    rhs.print(os);
    return os;
}

bool Peekback_Stack::peekback(string &elem, int index) const
{
    if (empty())
        return false;
    else if (!check_index(index))
        return false;
    else
        elem = _stack[index];
    return true;
}

bool Peekback_Stack::check_index(int index) const
{
    if (index < 0 || index >= _stack.max_size())
        return false;
    return true;
}
