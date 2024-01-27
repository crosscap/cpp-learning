#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string name() const { return name; }
    std::string address() const { return address; }
};