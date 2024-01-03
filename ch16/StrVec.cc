#include "StrVec.h"

using std::make_move_iterator;
using std::pair;
using std::string;
using std::uninitialized_copy;

StrVec::StrVec(std::initializer_list<string> li)
{
	auto newdata = alloc_n_copy(li.begin(), li.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec()
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}

	return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

void StrVec::reserve(size_t n)
{
	if (n > capacity())
		reallocate(n);
}

void StrVec::resize(size_t n, const string &s)
{
	if (n < size())
		while (size() != n)
			alloc.destroy(--first_free);
	else {
		while (size() != n)
			push_back(s);
	}
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()),
	                               make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

void StrVec::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	else
		for (auto iterl = lhs.begin(), iterr = rhs.begin(), end = lhs.end();
		     iterl != end; ++iterl, ++iterr)
			if (*iterl != *iterr)
				return false;
	return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	for (auto iterl = lhs.begin(), iterr = rhs.begin(), endl = lhs.end(), endr = rhs.end();
	     iterl != endl && iterr != endr; ++iterl, ++iterr)
		if (*iterl < *iterr)
			return true;
		else if (*iterl > *iterr)
			return false;
	if (lhs.size() < rhs.size())
		return true;
	else
		return false;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
	for (auto iterl = lhs.begin(), iterr = rhs.begin(), endl = lhs.end(), endr = rhs.end();
	     iterl != endl && iterr != endr; ++iterl, ++iterr)
		if (*iterl < *iterr)
			return true;
		else if (*iterl > *iterr)
			return false;
	if (lhs.size() <= rhs.size())
		return true;
	else
		return false;
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs);
}