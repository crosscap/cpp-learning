#include "Sales_item.h"
#include <iostream>
#include <iterator>

using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	istream_iterator<Sales_item> item_iter(std::cin), eof;
	ostream_iterator<Sales_item> out_iter(std::cout, "\n");
	Sales_item sum = *item_iter++;
	if (item_iter != eof) {
		if (item_iter->isbn() == sum.isbn())
			sum += *item_iter++;
		else {
			*out_iter++ = sum;
			sum = *item_iter++;
		}
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	*out_iter++ = sum;

	return 0;
}
