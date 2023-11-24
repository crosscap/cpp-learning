#include "Sales_data.h"
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

void sort_isbn(vector<Sales_data> &vsd)
{
	sort(vsd.begin(), vsd.end(),
	     [](const Sales_data &sd1, const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); });
}