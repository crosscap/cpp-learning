#ifndef VEC_H
#define VEC_H
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

using std::make_move_iterator;
using std::pair;
using std::string;
using std::uninitialized_copy;

template <typename T>
class Vec
{
public:
	Vec()
		: elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T>);
	Vec(const Vec &);
	Vec(Vec &&) noexcept;
	Vec &operator=(const Vec &);
	Vec &operator=(Vec &&) noexcept;
	~Vec();

	void push_back(const T &);
	void push_back(T &&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; }
	void reserve(size_t n);
	void resize(size_t n, const T &);

private:
	static std::allocator<T> alloc;
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	std::pair<T *, T *>
	alloc_n_copy(const T *, const T *);
	void free();
	void reallocate();
	void reallocate(size_t);
	T *elements;
	T *first_free;
	T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(std::initializer_list<T> li)
{
	auto newdata = alloc_n_copy(li.begin(), li.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(const Vec<T> &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T>::~Vec()
{
	free();
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec<T> &&rhs) noexcept
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

template <typename T>
void Vec<T>::push_back(const T &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::push_back(T &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
	if (n > capacity())
		reallocate(n);
}

template <typename T>
void Vec<T>::resize(size_t n, const T &s)
{
	if (n < size())
		while (size() != n)
			alloc.destroy(--first_free);
	else {
		while (size() != n)
			push_back(s);
	}
}

template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
void Vec<T>::reallocate()
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

template <typename T>
void Vec<T>::reallocate()
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

template <typename T>
void Vec<T>::reallocate(size_t newcapacity)
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
#endif