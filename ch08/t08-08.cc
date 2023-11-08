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
    std::ofstream output(argv[2], std::ofstream::out | std::ofstream::app);

    if (!input || !output) {
        cout << "can't open files" << endl;
        return -1;
    }

    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
}