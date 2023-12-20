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
	virtual ~Quote() = default;

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ostream &debug(ostream & = cout) const;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc) { }

	double net_price(std::size_t n) const override;
	ostream &debug(ostream & = cout) const;

private:
	std::size_t min_qty;
	double discount = 0.0;
};

class Limit_quote : public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc) { }

	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty;
	double discount = 0.0;
};

inline ostream &Quote::debug(ostream & os) const
{
	os << "bookNo: " << bookNo << " price: " << price;
}

inline double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1.0 - discount) * price;
	else
		return cnt * price;
}

inline ostream &Bulk_quote::debug(ostream & os) const
{
	Quote::debug() << " ";
	os << "min_qty: " << min_qty << " discount: " << discount;
}

inline double Limit_quote::net_price(std::size_t cnt) const
{
	if (cnt <= min_qty)
		return cnt * (1.0 - discount) * price;
	else
		return min_qty * (1.0 - discount) * price + (cnt - min_qty) * price;
}