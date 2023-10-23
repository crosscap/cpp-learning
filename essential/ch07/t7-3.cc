#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
public:
    virtual ~Stack() { }

    void pop(string &);
    void push(const string &);
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

void Stack::pop(string &elem)
{
    if (empty()) {
        throw(PopEmpty());
    } else {
        elem = _stack.back();
        _stack.pop_back();
    }
}

void Stack::push(const string &elem)
{
    if (full())
        throw PushFull();
    _stack.push_back(elem);
}

bool Stack::peek(string &elem) const
{
    if (empty())
        return false;
    elem = _stack.back();
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

class StackException : public exception {
public:
    StackException(const char *what) : _what(what) { }
    const char *what() const noexcept { return _what.c_str(); }
protected:
    string _what;
};

class PopEmpty : public StackException{
public:
    PopEmpty() : StackException("Pop on Empty Stack"){ }
};

class PushFull : public StackException{
public:
    PushFull() : StackException("Push on Full Stack"){ }
};
