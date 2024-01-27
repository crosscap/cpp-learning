#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using std::pair;
using std::uninitialized_copy;
using std::vector;

class String
{
public:
	String()
		: elements(nullptr), first_free(nullptr), cap(nullptr) { }
	String(const char *);
	String(const String &);
	String(String &&) noexcept;
	String &operator=(const String &);
	String &operator=(String &&) noexcept;
	~String();

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

String::String(const char *chs)
{
	std::cout << "String(const char *chs)" << std::endl;
	size_t length;
	for (length = 0; chs[length] != '\0'; ++length)
		continue;
	auto newdata = alloc_n_copy(chs, chs + length);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(const String &s)
{
	std::cout << "String(const String &s)" << std::endl;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(String &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	std::cout << "String(String &&s)" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}

String::~String()
{
	free();
}

String &String::operator=(const String &rhs)
{
	std::cout << "operator=(const String &rhs)" << std::endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String &String::operator=(String &&rhs) noexcept
{
	std::cout << "operator=(String &&rhs)" << std::endl;
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

int main()
{
	vector<String> vs;
	String s1("One"), s2("Tow");
	String s3(s2);
	s3 = String("Three");
	std::cout << "One" << std::endl;
	vs.push_back(s1);
	std::cout << "1" << std::endl;
	std::cout << "Tow" << std::endl;
	vs.push_back(std::move(s2));
	std::cout << "2" << std::endl;
	std::cout << "Three" << std::endl;
	vs.push_back(String("Three"));
	std::cout << "3" << std::endl;
	std::cout << "Four" << std::endl;
	vs.push_back("Four");
	std::cout << "4" << std::endl;

	return 0;
}