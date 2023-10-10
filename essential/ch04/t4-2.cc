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
    stack.push("good");
    stack.push("world");
    elem = "goof";
    if (stack.find(elem))
        cout << elem << " exist!" << std::endl;
    else
        cout << elem << " not exist!" << std::endl;
    elem = "world";
    cout << "has " << stack.count(elem) << ' ' << elem
         << " in stack!" << std::endl;
    if (!stack.full())
        cout << "not full!\n";
    cout << "size of stack is " << stack.size() << std::endl;
    stack.peek(elem);
    cout << "top of stack is " << elem << std::endl;
    stack.pop(elem);
    cout << "pop is " << elem << std::endl;

    return 0;
}