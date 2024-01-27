#include "String.h"

using std::pair;
using std::uninitialized_copy;

String::String(const char *chs)
{
	size_t length;
	for (length = 0; chs[length] != '\0'; ++length)
		continue;
	auto newdata = alloc_n_copy(chs, chs + length);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(String &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

String::~String()
{
	free();
}

String &String::operator=(const String &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String &String::operator=(String &&rhs) noexcept
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

void String::push_back(const char ch)
{
	chk_n_alloc();
	alloc.construct(first_free++, ch);
}

void String::reserve(size_t n)
{
	if (n > capacity())
		reallocate(n);
}

void String::resize(size_t n, const char ch)
{
	if (n < size())
		while (size() != n)
			alloc.destroy(--first_free);
	else {
		while (size() != n)
			push_back(ch);
	}
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void String::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
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

void String::reallocate(size_t newcapacity)
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