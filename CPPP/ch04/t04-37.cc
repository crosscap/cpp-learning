#include <iostream>
#include <string>

using std::string;

int main()
{
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    // pv = (void *) ps;
    pv = const_cast<void*>(static_cast<const void *>(ps));

    // i = int(*pc);
    i = static_cast<int>(*pc);

    // pv = &d;
    pv = static_cast<void*>(&d);

    // pc = (char*)pv;
    pc = static_cast<char*>(pv);
}