#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		: bookNo(book), price(sales_price) { }
	Quote(const Quote &) = default;
	Quote(Quote &&) = default;
	Quote &operator=(const Quote &) = default;
	Quote &operator=(Quote &&) = default;
	virtual ~Quote() = default;

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ostream &debug(ostream & = cout) const;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), quantity(qty), discount(disc) { }

	double net_price(std::size_t n) const override = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote;
	double net_price(std::size_t n) const override;
};

inline ostream &Quote::debug(ostream &os) const
{
	os << "bookNo: " << bookNo << " price: " << price;
	return os;
}

inline double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1.0 - discount) * price;
	else
		return cnt * price;
}
