#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;

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
	bool operator<(const HasPtr &);
	std::ostream &print(std::ostream & = std::cout);

private:
	std::string *ps;
	int i;
	std::size_t *use;
};

int main()
{
	vector<HasPtr> vhas;

	vhas.emplace_back(HasPtr("csgo"));
	vhas.emplace_back(HasPtr("cs2"));
	vhas.emplace_back(HasPtr("valorant"));
	std::sort(vhas.begin(), vhas.end());
	for (auto &r : vhas)
		r.print();

	return 0;
}

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

bool HasPtr::operator<(const HasPtr &rhs)
{
	std::cout << "function operator<" << std::endl;
	if (*this->ps < *rhs.ps)
		return true;
	else if (this->i < rhs.i)
		return true;
	else
		return false;
}

std::ostream &HasPtr::print(std::ostream &os)
{
	os << *ps << std::endl;
	return os;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	std::cout << "function swap" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}