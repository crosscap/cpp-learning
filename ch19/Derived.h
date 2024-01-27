#ifndef DERIVED_H
#define DERIVED_H

#include <typeinfo>

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() = default;
	virtual ~Base() = default;
protected:
	virtual bool equal(const Base&) const;
	int val;

};

class Derived : public Base
{
public:
	Derived() = default;
	virtual ~Derived() = default;
protected:
	bool equal(const Base&) const;
	int dval;
};

bool Base::equal(const Base&rhs) const
{
	return val == rhs.val;
}

bool Derived::equal(const Base&rhs) const
{
	auto r = dynamic_cast<const Derived &>(rhs);
	return val == r.val && dval == r.dval;
}

bool operator==(const Base &lhs, const Base&rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}
#endif
