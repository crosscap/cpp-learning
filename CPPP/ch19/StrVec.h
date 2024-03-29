#ifndef STRVEC_H
#define STRVEC_H
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

void *operator new(size_t size);
void operator delete(void *mem) noexcept;

class StrVec
{
public:
	StrVec()
		: elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	StrVec &operator=(const StrVec &);
	StrVec &operator=(StrVec &&) noexcept;
	~StrVec();

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
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
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

void *operator new(size_t size)
{
	if (void *mem = std::malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept
{
	std::free(mem);
}
#endif