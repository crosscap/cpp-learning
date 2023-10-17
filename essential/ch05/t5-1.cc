#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
public:
    virtual ~Stack() { }

    virtual bool pop(string &) = 0;
    virtual bool push(const string &) = 0;
    virtual bool peek(string &) const = 0;

    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;

    virtual void print(ostream & = cout) const = 0;
};

class LIFO_Stack : public Stack
{
public:
    bool pop(string &);
    bool push(const string &);
    bool peek(string &) const;

    int size() const { return _stack.size(); }
    bool empty() const { return _stack.empty(); }
    bool full() const { return _stack.size() == _stack.max_size(); }

    void print(ostream & = cout) const;

protected:
    LIFO_Stack() { }
    vector<string> _stack;
};

class Peekback_Stack : public Stack
{
public:
    bool pop(string &);
    bool push(const string &);
    bool peek(string &) const;
    bool peekback(string &, int) const;

    int size() const { return _stack.size(); }
    bool empty() const { return _stack.empty(); }
    bool full() const { return _stack.size() == _stack.max_size(); }

    void print(ostream & = cout) const;

protected:
    Peekback_Stack() { }

    bool check_index(int) const;
    vector<string> _stack;
};

bool LIFO_Stack::pop(string &elem)
{
    if (empty()) {
        return false;
    } else {
        elem = _stack.back();
        _stack.pop_back();
        return true;
    }
}

bool LIFO_Stack::push(const string &elem)
{
    if (full())
        return false;
    _stack.push_back(elem);
    return true;
}

bool LIFO_Stack::peek(string &elem) const
{
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}

void LIFO_Stack::print(ostream &os) const
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

bool Peekback_Stack::pop(string &elem)
{
    if (empty()) {
        return false;
    } else {
        elem = _stack.back();
        _stack.pop_back();
        return true;
    }
}

bool Peekback_Stack::push(const string &elem)
{
    if (full())
        return false;
    _stack.push_back(elem);
    return true;
}

bool Peekback_Stack::peek(string &elem) const
{
    if (empty())
        return false;
    elem = _stack.back();
    return true;
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

void Peekback_Stack::print(ostream &os) const
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
