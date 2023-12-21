#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Quote
{
public:
	Quote() { cout << "Quote() " << endl; }
	Quote(const std::string &book, double sales_price)
		: bookNo(book), price(sales_price)
	{
		cout << "Quote(const string &book, double sales_price) ";
		debug() << endl;
	}
	Quote(const Quote &orig)
		: bookNo(orig.bookNo), price(orig.price)
	{
		cout << "Quote(const Quote &orig) ";
		debug() << endl;
	}
	Quote(Quote &&orig)
		: bookNo(orig.bookNo), price(orig.price)
	{
		cout << "Quote(Quote &&orig) ";
		debug() << endl;
	}
	Quote &operator=(const Quote &);
	Quote &operator=(Quote &&);
	virtual ~Quote()
	{
		cout << "~Quote() ";
		debug() << endl;
	}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ostream &debug(ostream & = cout) const;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

inline Quote &Quote::operator=(const Quote &rhs)
{
	cout << "operator=(const Quote &rhs) ";
	debug() << endl;

	bookNo = rhs.bookNo;
	price = rhs.price;

	return *this;
}

inline Quote &Quote::operator=(Quote &&rhs)
{
	cout << "operator=(Quote &&rhs) ";
	debug() << endl;

	bookNo = rhs.bookNo;
	price = rhs.price;

	return *this;
}

inline ostream &Quote::debug(ostream &os) const
{
	os << "Quote ";
	os << "bookNo: " << bookNo << " price: " << price;
	return os;
}

class Disc_quote : public Quote
{
public:
	Disc_quote() { cout << "Disc_quote() " << endl; }
	Disc_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), quantity(qty), discount(disc)
	{
		cout << "Disc_quote(const std::string &book, double p, size_t qty, double disc) ";
		debug() << endl;
	}
	Disc_quote(const Disc_quote &orig)
		: Quote(orig), quantity(orig.quantity), discount(orig.discount)
	{
		cout << "Disc_quote(const Disc_quote &orig) ";
		debug() << endl;
	}
	Disc_quote(Disc_quote &&orig)
		: Quote(orig), quantity(orig.quantity), discount(orig.discount)
	{
		cout << "Disc_quote(Disc_quote &&orig) ";
		debug() << endl;
	}
	Disc_quote &operator=(const Disc_quote &);
	Disc_quote &operator=(Disc_quote &&);
	virtual ~Disc_quote()
	{
		cout << "~Disc_quote() ";
		debug() << endl;
	}

	double net_price(std::size_t n) const override = 0;
	ostream &debug(ostream & = cout) const override;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

inline Disc_quote &Disc_quote::operator=(const Disc_quote &rhs)
{
	cout << "operator=(const Disc_quote &rhs) ";
	debug() << endl;

	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;

	return *this;
}

inline Disc_quote &Disc_quote::operator=(Disc_quote &&rhs)
{
	cout << "operator=(Disc_quote &&rhs) ";
	debug() << endl;

	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;

	return *this;
}

inline ostream &Disc_quote::debug(ostream &os) const
{
	os << "Disc_quote ";
	this->Quote::debug();
	os << " quantity: " << quantity << " discount: " << discount;
	return os;
}

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() { cout << "Bulk_quote() " << endl; }
	Bulk_quote(const std::string &book, double price, size_t qty, double disc)
		: Disc_quote(book, price, qty, disc)
	{
		cout << "Bulk_quote(const std::string &book, double p, size_t qty, double disc) ";
		debug() << endl;
	}
	Bulk_quote(const Bulk_quote &orig)
		: Disc_quote(orig)
	{
		cout << "Bulk_quote(const Disc_quote &orig) ";
		debug() << endl;
	}
	Bulk_quote(Bulk_quote &&orig)
		: Disc_quote(orig)
	{
		cout << "Bulk_quote(const Disc_quote &orig) ";
		debug() << endl;
	}
	Bulk_quote &operator=(const Bulk_quote &);
	Bulk_quote &operator=(Bulk_quote &&);
	virtual ~Bulk_quote()
	{
		cout << "~Bulk_quote() ";
		debug() << endl;
	}

	double net_price(std::size_t n) const override;
	ostream &debug(ostream & = cout) const override;
};

inline Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
	cout << "operator=(const Bulk_quote &rhs) ";
	debug() << endl;

	Disc_quote::operator=(rhs);

	return *this;
}

inline Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)
{
	cout << "operator=(Bulk_quote &&rhs) ";
	debug() << endl;

	Disc_quote::operator=(rhs);

	return *this;
}

inline double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1.0 - discount) * price;
	else
		return cnt * price;
}

inline ostream &Bulk_quote::debug(ostream &os) const
{
	os << "Bulk_quote ";
	this->Disc_quote::debug();
	return os;
}

class Limit_quote : public Disc_quote
{
public:
	Limit_quote() { cout << "Limit_quote() " << endl; }
	Limit_quote(const std::string &book, double price, size_t qty, double disc)
		: Disc_quote(book, price, qty, disc)
	{
		cout << "Limit_quote(const std::string &book, double p, size_t qty, double disc) ";
		debug() << endl;
	}
	Limit_quote(const Limit_quote &orig)
		: Disc_quote(orig)
	{
		cout << "Limit_quote(const Disc_quote &orig) ";
		debug() << endl;
	}
	Limit_quote(Limit_quote &&orig)
		: Disc_quote(orig)
	{
		cout << "Limit_quote(const Disc_quote &orig) ";
		debug() << endl;
	}
	Limit_quote &operator=(const Limit_quote &);
	Limit_quote &operator=(Limit_quote &&);
	virtual ~Limit_quote()
	{
		cout << "~Limit_quote() ";
		debug() << endl;
	}

	double net_price(std::size_t n) const override;
	ostream &debug(ostream & = cout) const override;
};

inline double Limit_quote::net_price(std::size_t cnt) const
{
	if (cnt <= quantity)
		return cnt * (1.0 - discount) * price;
	else
		return quantity * (1.0 - discount) * price + (cnt - quantity) * price;
}

inline ostream &Limit_quote::debug(ostream &os) const
{
	os << "Limit_quote ";
	this->Disc_quote::debug();
	return os;
}

inline Limit_quote &Limit_quote::operator=(const Limit_quote &rhs)
{
	cout << "operator=(const Limit_quote &rhs) ";
	debug() << endl;

	Disc_quote::operator=(rhs);

	return *this;
}

inline Limit_quote &Limit_quote::operator=(Limit_quote &&rhs)
{
	cout << "operator=(Limit_quote &&rhs) ";
	debug() << endl;

	Disc_quote::operator=(rhs);

	return *this;
}