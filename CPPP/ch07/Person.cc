#include "Person.h"

std::ostream &print(std::ostream &os, const Person &item)
{
    os << "The name of this Person class is " << item.getName() << '\n'
       << "The address of this Person class is " << item.getAddress();
    return os;
}

std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}