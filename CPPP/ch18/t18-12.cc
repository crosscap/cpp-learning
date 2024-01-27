#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

namespace chapter10
{
class QueryResult;

class TextQuery
{
public:
	using line_no = vector<string>::size_type;

	TextQuery(ifstream &infile);

	QueryResult query(const string &s) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
	friend ostream &print(ostream &outfile, const QueryResult &query);

public:
	using line_no = vector<string>::size_type;

	QueryResult(const string &s,
	            shared_ptr<set<line_no>> p,
	            shared_ptr<vector<string>> f)
		: sought(s), lines(p), file(f) { }

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &infile)
	: file(new vector<string>)
{
	string text;
	while (getline(infile, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &query)
{
	os << query.sought << " occurs " << query.lines->size() << " times" << endl;
	for (auto num : *query.lines)
		cout << "\t(line " << num + 1 << " ) " << *(query.file->begin() + num) << endl;

	return os;
}

} // namespace chapter10

namespace chapter15
{
class chapter10::QueryResult;

class Query_base
{
	friend class Query;

protected:
	using line_no = chapter10::TextQuery::line_no;
	virtual chapter10::QueryResult eval(const chapter10::TextQuery &) const = 0;
	virtual std::string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);

public:
	Query(const std::string &);
	chapter10::QueryResult eval(const chapter10::TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }

private:
	Query(std::shared_ptr<Query_base> query)
		: q(query) { }
	std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s)
		: query_word(s) { }
	chapter10::QueryResult eval(const chapter10::TextQuery &t) const override { return t.query(query_word); }
	std::string rep() const override { return query_word; }
	std::string query_word;
};

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q)
		: query(q) { }
	chapter10::QueryResult eval(const chapter10::TextQuery &) const override;
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
	chapter10::QueryResult eval(const chapter10::TextQuery &) const override;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "|") { }
	chapter10::QueryResult eval(const chapter10::TextQuery &) const override;
};

inline Query::Query(const std::string &s)
	: q(new WordQuery(s)) { }

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

std::ostream &operator<<(std::ostream &os, const Query &query);
} // namespace chapter15
