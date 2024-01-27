#include <algorithm>

#include "StrVec.h"

using std::for_each;
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

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n)
{
	if (n > capacity())
		reallocate(n);
}

void StrVec::resize(size_t n, const string &s)
{
	if (n < size())
		for_each(elements + n, first_free, [] (string &s) {alloc.destroy(&s);});

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
		for_each(first_free, elements, [] (string &s) {alloc.destroy(&s);});
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