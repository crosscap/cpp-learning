#ifndef STRVEC_H
#define STRVEC_H
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
	friend bool operator==(const StrVec &, const StrVec &);
	friend bool operator!=(const StrVec &, const StrVec &);
	friend bool operator<(const StrVec &, const StrVec &);
	friend bool operator<=(const StrVec &, const StrVec &);
	friend bool operator>(const StrVec &, const StrVec &);
	friend bool operator>=(const StrVec &, const StrVec &);

public:
	StrVec()
		: elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	~StrVec();

	StrVec &operator=(const StrVec &);
	StrVec &operator=(StrVec &&) noexcept;
	StrVec &operator=(std::initializer_list<std::string>);
	std::string &operator[](std::size_t n) { return elements[n]; }
	const std::string &operator[](std::size_t n) const { return elements[n]; }

	void push_back(const std::string &);
	void push_back(std::string &&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	void reserve(size_t n);
	void resize(size_t n, const std::string & = "");

private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc();

	std::pair<std::string *, std::string *>
	alloc_n_copy(const std::string *, const std::string *);
	void free();
	void reallocate();
	void reallocate(size_t);
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

bool operator==(const StrVec &, const StrVec &);
bool operator!=(const StrVec &, const StrVec &);
bool operator<(const StrVec &, const StrVec &);
bool operator<=(const StrVec &, const StrVec &);
bool operator>(const StrVec &, const StrVec &);
bool operator>=(const StrVec &, const StrVec &);

inline void StrVec::chk_n_alloc()
{
	if (size() == capacity()) reallocate();
}
#endif