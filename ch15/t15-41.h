#ifndef T15_41_H
#define T15_41_H

#include <iostream>
#include <string>

#include "QueryResult.h"
#include "TextQuery.h"

class QueryResult;

class Query_base
{
	friend class Query;

protected:
	using line_no = TextQuery::line_no;
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
	void inc_counter() { ++counter; }
	void dec_counter() { --counter; }
	size_t get_counter() { return counter; }

private:
	size_t counter = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);

public:
	Query(const std::string &);
	Query(const Query &orig)
		: q(orig.q) { q->inc_counter(); }
	Query &operator=(const Query &);
	~Query();

	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }

private:
	Query(Query_base *query)
		: q(query) { q->inc_counter(); }
	Query_base *q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s)
		: query_word(s) { }
	QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
	std::string rep() const override { return query_word; }
	std::string query_word;
};

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q)
		: query(q) { }
	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s)
		: lhs(l), rhs(r), opSym(s) { }
	std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "&") { }
	QueryResult eval(const TextQuery &) const override;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "|") { }
	QueryResult eval(const TextQuery &) const override;
};

inline Query::Query(const std::string &s)
	: q(new WordQuery(s)) { }

inline Query operator~(const Query &operand)
{
	return new NotQuery(operand);
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}

std::ostream &operator<<(std::ostream &os, const Query &query);

#endif