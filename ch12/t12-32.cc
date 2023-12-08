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

using line_no = vector<string>::size_type;

class StrBlobPtr;
class QueryResult;

class StrBlob
{
	friend class StrBlobPtr;

public:
	typedef vector<string>::size_type size_type;

	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il)
		: data(make_shared<vector<string>>()) {}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string &front();
	string &front() const;
	string &back();
	string &back() const;
	string &at(std::size_t i) const { return data->at(i); }
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
	friend bool StrBlobPtrEqual(const StrBlobPtr &, const StrBlobPtr &);

public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

	string &deref() const;
	StrBlobPtr &incr();

private:
	shared_ptr<vector<string>>
	check(size_t, const string &) const;

	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};

class TextQueriy
{
public:
	TextQueriy(ifstream &infile);

	QueryResult query(const string &s) const;

private:
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
	friend ostream &print(ostream &outfile, const QueryResult &query);

public:
	QueryResult(const string &s,
	            shared_ptr<set<line_no>> p,
	            StrBlob f)
		: sought(s), lines(p), file(f) {}

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	StrBlob file;
};

TextQueriy::TextQueriy(ifstream &infile) : file()
{
	string text;
	while (getline(infile, text)) {
		file.push_back(text);
		int n = file.size() - 1;
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

QueryResult TextQueriy::query(const string &sought) const
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
		cout << "\t(line " << num + 1 << " ) " << (query.file.at(num)) << endl;

	return os;
}

inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

bool StrBlobPtrEqual(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

// function of StrBlob
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string &StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

// function of StrBlobPtr
string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "incerement past end of StrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>>
StrBlobPtr::check(std::size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

void runQueries(ifstream &infile)
{
	TextQueriy tq(infile);

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream ifile("input.txt");

	runQueries(ifile);

	return 0;
}