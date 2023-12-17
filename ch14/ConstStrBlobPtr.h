#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "StrBlob.h"

using std::shared_ptr;
using std::string;
using std::vector;

class StrBlobPtr;
class ConstStrBlobPtr;

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr()
		: curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) { }

	const string &operator*() const;
	const string *operator->() const;

	std::string &deref() const;
	ConstStrBlobPtr &incr();

private:
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif