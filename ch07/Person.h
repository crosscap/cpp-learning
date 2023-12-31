#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class Person {
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);
public:
    Person() = default;
    Person(std::string n, std::string a) : name(n), address(a) { }
    explicit Person(std::string n) : name(n) { }
    explicit Person(std::istream &is) { read(is, *this); }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};

std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);

#endif