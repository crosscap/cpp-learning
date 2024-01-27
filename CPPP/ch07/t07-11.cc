#include "Sales_data.h"

int main()
{
    Sales_data sd0;
    Sales_data sd1("C++ primer");
    Sales_data sd2("essential C++", 10, 42);
    Sales_data sd3(std::cin);

    print(std::cout, sd0) << std::endl;
    print(std::cout, sd1) << std::endl;
    print(std::cout, sd2) << std::endl;
    print(std::cout, sd3) << std::endl;

    return 0;
}