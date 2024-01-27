#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <unordered_set>

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);

public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(p * n) {}
	explicit Sales_data(const std::string &s) : bookNo(s) {}
	explicit Sales_data(std::istream &is) { read(is, *this); }
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	inline double avg_price() const;

	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

size_t hasher(const Sales_data &sd)
{
	return std::hash<std::string>() (sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

using SD_multiset = std::unordered_multiset<Sales_data, decltype(hasher) *, decltype((eqOp))>;
SD_multiset bookstore(42, hasher, eqOp);
#endif