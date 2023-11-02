#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Person {
    Person() = default;
    Person(std::string n, std::string a) : name(n), address(a) { }
    Person(std::string n) : name(n) { }
    Person(std::istream &is) { read(is, *this); }
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);

#endif