#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "Sales_data.h"

using std::accumulate;
using std::cout;
using std::endl;
using std::equal_range;
using std::get;
using std::istream;
using std::make_pair;
using std::ostream;
using std::pair;
using std::string;
using std::tuple;
using std::vector;

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator>
	mathes;
typedef pair<vector<Sales_data>::size_type,
             pair<vector<Sales_data>::const_iterator,
                  vector<Sales_data>::const_iterator>>
	mathes5;

bool compareIsbn(const Sales_data &, const Sales_data &);
vector<mathes> findBook(const vector<vector<Sales_data>> &, const string &);
void reportResults(istream &, ostream &, const vector<vector<Sales_data>> &);

vector<mathes5> findBook5(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<mathes5> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
	}
	return ret;
}

struct mathes6 {
	vector<Sales_data>::size_type sz;
	vector<Sales_data>::const_iterator beg, end;
};

vector<mathes6> findBook6(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<mathes6> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.emplace_back(it - files.cbegin(), found.first, found.second);
	}
	return ret;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}