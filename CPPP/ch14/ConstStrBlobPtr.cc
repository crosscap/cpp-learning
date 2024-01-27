#include "ConstStrBlobPtr.h"

// function of ConstStrBlobPtr

const string &ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
const string *ConstStrBlobPtr::operator->() const
{
	return &this->operator*();
}

std::string &ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
	check(curr, "incerement past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}