#include "Quote.h"

using std::ostream;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main()
{
	Quote book1("go", 10);
	Bulk_quote book2("go2", 20, 10, 0.1);
	double pay1 = print_total(std::cout, book1, 5);
	double pay2 = print_total(std::cout, book2, 5);
	double pay3 = print_total(std::cout, book2, 10);

	std::cout << pay1 << " " << pay2 << " " << pay3 << std::endl;
	return 0;
}