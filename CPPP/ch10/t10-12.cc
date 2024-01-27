#include "Sales_data.h"

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}