#include "Stack.h"

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

bool Stack::peek(string &elem)
{
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem)
{
    if (full())
        return false;
    _stack.push_back(elem);
    return true;
}

// t4-2 add down functions

bool Stack::find(const string &elem)
{
    for (auto ip = _stack.begin(); ip != _stack.end(); ++ip) {
        if (*ip == elem)
            return true;
    }
    return false;
}

int Stack::count(const string &elem)
{
    int count = 0;
    for (auto ip = _stack.begin(); ip != _stack.end(); ++ip) {
        if (*ip == elem)
            ++count;
    }
    return count;
}