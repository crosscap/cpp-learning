#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    Sales_data total;
    std::ifstream input(argv[1]);

    if (!input) {
        cout << "can't open files" << endl;
        return -1;
    }

    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
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