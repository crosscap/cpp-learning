#include <string>

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);

public:
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
	HasPtr(const HasPtr &orig)
		: ps(orig.ps), i(orig.i), use(orig.use) { ++*use; }
	HasPtr(HasPtr &&p) noexcept
		: ps(p.ps), i(p.i) { p.ps = 0; }
	~HasPtr();

	HasPtr &operator=(const HasPtr &);
	HasPtr &operator=(HasPtr &&) noexcept;

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

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (!--*use) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;

	return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
	if (this != &rhs) {
		delete ps;
		ps = std::move(rhs.ps);
		i = rhs.i;
		use = rhs.use;
		rhs.ps = nullptr;
		rhs.i = 0;
	}
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}