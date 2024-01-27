#include <iostream>

#include "Sales_data.h"

void fun1()
{
	Sales_data item1, item2;
	while (std::cin >> item1 >> item2) {
		try {
			item1 += item2;
		} catch (const isbn_mismatch &e) {
			std::cerr << e.what() << ": left isbn(" << e.left << ")" << "right isbn(" << e.right << ")" << std::endl;
		}
	}
}

void fun2()
{
	Sales_data item1, item2;
	while (std::cin >> item1 >> item2) {
		item1 += item2;
	}
}