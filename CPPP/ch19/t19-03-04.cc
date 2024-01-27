#include <typeinfo>

using std::bad_cast;

class A
{
public:
	A() = default;
	virtual ~A() { }
};

class B : public A
{
public:
	B() = default;
	virtual ~B() { }
};

class C : virtual public B
{
public:
	C() = default;
	virtual ~C() { }
};

class D : public B, public A
{
public:
	D() = default;
	virtual ~D() { }
};

void try_dynamic_cast(A *pa)
{
	if (C *pc = dynamic_cast<C *>(pa)) {

	} else {
	}

	try {
		const C &rc = dynamic_cast<C &>(*pa);
	} catch (bad_cast) {
	}
}
