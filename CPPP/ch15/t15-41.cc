#include <algorithm>

#include "t15-41.h"

using std::inserter;

Query &Query::operator=(const Query &rhs)
{
	if (this != &rhs) {
		q = rhs.q;
		q->inc_counter();
	}
	return *this;
}

Query::~Query()
{
	q->dec_counter();
	if (!q->get_counter())
		delete q;
}

std::ostream &operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(),
	                      right.begin(), right.end(),
	                      inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}