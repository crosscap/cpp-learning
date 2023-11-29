#include <list>
#include <set>
#include <string>

#include "Sales_data.h"

using std::list;
using std::multiset;
using std::string;

bool compareIsbnlower(const Sales_data &sd1, const Sales_data &sd2);

int main()
{
	multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
		bookstore(compareIsbnlower);
}

bool compareIsbnlower(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}