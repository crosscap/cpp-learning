#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total;

    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, total)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
}