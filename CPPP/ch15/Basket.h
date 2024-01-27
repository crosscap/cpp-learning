#include <memory>
#include <set>

#include "new_Quote.h"

using std::make_shared;
using std::shared_ptr;

double print_total(ostream &os, const Quote &item, size_t n);

class Basket
{
public:
	double total_receipt(std::ostream &) const;

	void add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}