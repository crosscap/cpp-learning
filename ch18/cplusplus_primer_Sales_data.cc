#include "cplusplus_primer_Sales_data.h"

namespace cplusplus_primer
{
Sales_data::Sales_data(const Sales_data &orig)
	: bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) { }

Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;

	return *this;
}

Sales_data &Sales_data::operator=(const std::string &rhs)
{
	bookNo = rhs;
	return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum -= rhs;
	return sum;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
	       lhs.units_sold == rhs.units_sold &&
	       lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
} // namespace cplusplus_primer