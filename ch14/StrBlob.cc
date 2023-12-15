#include "StrBlob.h"

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

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data <= *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}

// function of StrBlobPtr
StrBlobPtr &StrBlobPtr::operator++()
{
	check(curr, "incerement past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decerement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

std::string &StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const
{
	return &this->operator*();
}

std::string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr < rhs.curr);
	else
		return false;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr <= rhs.curr);
	else
		return false;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

StrBlobPtr operator+(const StrBlobPtr &lhs, int n)
{
	StrBlobPtr ret = lhs;
	ret.curr += n;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, int n)
{
	StrBlobPtr ret = lhs;
	ret.curr += n;
	return ret;
}