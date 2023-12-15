#ifndef STRING_H
#define STRING_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

class String
{
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	friend bool operator<(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator>=(const String &, const String &);

public:
	String()
		: elements(nullptr), first_free(nullptr), cap(nullptr) { }
	String(const char *);
	String(const String &);
	String(String &&) noexcept;
	~String();

	String &operator=(const String &);
	String &operator=(String &&rhs) noexcept;
	char operator[](std::size_t n) { return elements[n]; }
	const char operator[](std::size_t n) const { return elements[n]; }

	void push_back(const char);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	char *begin() const { return elements; }
	char *end() const { return first_free; }
	void reserve(size_t n);
	void resize(size_t n, const char = '\0');

private:
	static std::allocator<char> alloc;
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	std::pair<char *, char *>
	alloc_n_copy(const char *, const char *);
	void free();
	void reallocate();
	void reallocate(size_t);
	char *elements;
	char *first_free;
	char *cap;
};

std::allocator<char> String::alloc;

std::ostream &operator<<(std::ostream &os, const String &s);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>(const String &, const String &);
bool operator>=(const String &, const String &);
#endif