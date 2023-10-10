#include "Stack.h"
using std::cout;

int main()
{
    Stack stack;
    string elem;

    if (stack.empty())
        cout << "empty!\n";
    stack.push("hello");
    stack.push("world");
    if (!stack.full())
        cout << "not full!\n";
    cout << "size of stack is " << stack.size() << std::endl;
    stack.peek(elem);
    cout << "top of stack is " << elem << std::endl;
    stack.pop(elem);
    cout << "pop is " << elem << std::endl;

    return 0;
}