#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data operator-(const Sales_data &, const Sales_data &);
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, const Sales_data &);
	friend bool operator==(const Sales_data &, const Sales_data &);
	friend bool operator!=(const Sales_data &, const Sales_data &);

public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(const Sales_data &);
	explicit Sales_data(const std::string &s)
		: bookNo(s) { }
	explicit Sales_data(std::istream &is) { read(is, *this); }

	Sales_data &operator=(const Sales_data &);
	Sales_data &operator=(const std::string &);
	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator-=(const Sales_data &);

	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

	inline double avg_price() const;

private:

	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
Sales_data operator-(const Sales_data &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);
#endif