#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &orig);
	~HasPtr();

	HasPtr &operator=(const HasPtr &);

private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

HasPtr::~HasPtr()
{
	delete ps;
}

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
	delete ps;
	ps = new std::string(*rhs.ps);
	i = rhs.i;

	return *this;
}