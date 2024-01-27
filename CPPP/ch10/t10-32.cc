#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "Sales_item.h"

using std::accumulate;
using std::find_if;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::vector;

bool compareIsbnlower(const Sales_item &sd1, const Sales_item &sd2);

int main()
{
	std::ifstream inf("infiles.txt");
	istream_iterator<Sales_item> item_iter(inf), eof;
	ostream_iterator<Sales_item> out_iter(std::cout, "\n");
	vector<Sales_item> vsi;
	vector<Sales_item>::iterator next;

	if (item_iter != eof) {
		while (item_iter != eof)
			vsi.push_back(*item_iter++);
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	sort(vsi.begin(), vsi.end(), compareIsbnlower);
	for (auto iter = vsi.begin(), end = vsi.end(); iter != end;) {
		next = find_if(iter + 1, end,
		               [iter](Sales_item &now) { return iter->isbn() != now.isbn(); });
		out_iter = accumulate(iter, next, *iter);
		iter = next;
	}

	return 0;
}

bool compareIsbnlower(const Sales_item &sd1, const Sales_item &sd2)
{
	return sd1.isbn() < sd2.isbn();
}