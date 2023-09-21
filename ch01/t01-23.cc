#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item curritem, item;

    if (std::cin >> curritem)
    {
        int cnt = 1;
        while (std::cin >> item)
        {
            if (curritem.isbn() == item.isbn())
                ++cnt;
            else
            {
                std::cout << curritem.isbn() << " occures "
                          << cnt << " times" << std::endl;
                curritem = item;
                cnt = 1;
            }
        }
        std::cout << curritem.isbn() << " occures "
                  << cnt << " times" << std::endl;
    }
    return 0;
}
