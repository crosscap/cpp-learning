#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "Sales_data.h"

using std::accumulate;
using std::cout;
using std::endl;
using std::equal_range;
using std::get;
using std::istream;
using std::make_tuple;
using std::ostream;
using std::string;
using std::tuple;
using std::vector;

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator>
	mathes;

bool compareIsbn(const Sales_data &, const Sales_data &);
vector<mathes> findBook(const vector<vector<Sales_data>> &, const string &);
void reportResults(istream &, ostream &, const vector<vector<Sales_data>> &);

vector<mathes> findBook(const vector<vector<Sales_data>> &files,
                        const string &book)
{
	vector<mathes> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
	string s;
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
		}
		for (const auto &store : trans) {
			os << "store " << get<0>(store) << "sales: "
			   << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
		}
	}
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}