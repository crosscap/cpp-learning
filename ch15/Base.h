class Base
{
public:
	static void statmem();
};

class Derived : public Base
{
	void f(const Derived &);
};

void Derived::f(const Derived &derived_obj)
{
	Base::statmem();
	Derived::statmem();
	derived_obj.statmem();
	statmem();
}