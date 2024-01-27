#include <string>

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);

public:
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr &orig)
		: ps(orig.ps), i(orig.i), use(orig.use) { ++*use; }
	~HasPtr();

	HasPtr &operator=(HasPtr);

private:
	std::string *ps;
	int i;
	std::size_t *use;
};

HasPtr::~HasPtr()
{
	if (!--*use) {
		delete ps;
		delete use;
	}
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}