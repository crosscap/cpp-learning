#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, Sales_data &);

int main()
{
    Sales_data total;

    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
}