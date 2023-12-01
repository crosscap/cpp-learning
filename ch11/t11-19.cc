#include <list>
#include <set>
#include <string>

#include "Sales_data.h"

using std::list;
using std::multiset;
using std::string;
using std::pair;

bool compareIsbnlower(const Sales_data &sd1, const Sales_data &sd2);

int main()
{
	multiset<Sales_data, decltype(compareIsbnlower)> bookstore(compareIsbnlower);
	multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator
		bookstore_value = bookstore.begin();
}

bool compareIsbnlower(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}