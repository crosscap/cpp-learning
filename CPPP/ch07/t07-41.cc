#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data(const std::string &s, unsigned cnt, double price)
        : bookNo(s), units_sold(cnt), revenue(price * cnt)
    {
        cout << "using (s, n, p)" << endl;
    }
    Sales_data() : Sales_data("", 0, 0) { cout << "using ( )" << endl; }
    Sales_data(std::string s) : Sales_data(s, 0, 0)
    {
        cout << "using (s)" << endl;
    }
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
        cout << "using (is)" << endl;
    }
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data sd1("book", 42, 7);
    cout << "sd1 finished\n" << endl;
    Sales_data sd2;
    cout << "sd2 finished\n" << endl;
    Sales_data sd3("magazine");
    cout << "sd3 finished\n" << endl;
    Sales_data sd4(std::cin);
    cout << "sd4 finished\n" << endl;

    return 0;
}

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