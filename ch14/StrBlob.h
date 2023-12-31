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
	friend class ConstStrBlobPtr;

	friend bool operator==(const StrBlob &, const StrBlob &);
	friend bool operator!=(const StrBlob &, const StrBlob &);
	friend bool operator<(const StrBlob &, const StrBlob &);
	friend bool operator<=(const StrBlob &, const StrBlob &);
	friend bool operator>(const StrBlob &, const StrBlob &);
	friend bool operator>=(const StrBlob &, const StrBlob &);

public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob()
		: data(std::make_shared<vector<string>>()) { }
	StrBlob(std::initializer_list<std::string> il)
		: data(std::make_shared<vector<string>>(il)) { }

	std::string &operator[](std::size_t n) { return (*data)[n]; }
	const std::string &operator[](std::size_t n) const { return (*data)[n]; }

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
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
	friend StrBlobPtr operator+(const StrBlobPtr &, int);
	friend StrBlobPtr operator-(const StrBlobPtr &, int);

public:
	StrBlobPtr()
		: curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) { }

	std::string operator[](std::size_t n) { return (*wptr.lock())[n]; }
	const std::string operator[](std::size_t n) const { return (*wptr.lock())[n]; }
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string &operator*() const;
	std::string *operator->() const;

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

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
StrBlobPtr operator+(const StrBlobPtr &, int);
StrBlobPtr operator-(const StrBlobPtr &, int);

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