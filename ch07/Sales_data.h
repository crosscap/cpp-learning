#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

using std::string;

class Sales_data {
public:
    string &isbn();
    void combine(const Sales_data &);
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, Sales_data &);

#endif