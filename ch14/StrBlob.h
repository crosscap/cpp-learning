#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob &, const StrBlob &);
	friend bool operator!=(const StrBlob &, const StrBlob &);
	friend bool operator<(const StrBlob &, const StrBlob &);
	friend bool operator<=(const StrBlob &, const StrBlob &);
	friend bool operator>(const StrBlob &, const StrBlob &);
	friend bool operator>=(const StrBlob &, const StrBlob &);

public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<std::string> il)
		: data(std::make_shared<vector<string>>(il)) {}

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string &front();
	std::string &front() const;
	std::string &back();
	std::string &back() const;
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
	friend bool StrBlobPtrEqual(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

	std::string &deref() const;
	StrBlobPtr &incr();

private:
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);
bool StrBlobPtrEqual(const StrBlobPtr &, const StrBlobPtr &);
bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

#endif