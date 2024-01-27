class Class
{};

class Base : public Class
{
public:
	Base() { }
	Base(int num) { }
	Base(const Base &orig) { }
};

class D1 : virtual public Base
{
public:
	D1() { }
	D1(int num) : Base(num) { }
	D1(const D1 &orig) : Base(orig) { }
};

class D2 : virtual public Base
{
public:
	D2() { }
	D2(int num) : Base(num) { }
	D2(const D2 &orig) : Base(orig) { }
};

class MI : public D1, public D2
{
public:
	MI() { }
	MI(int num) : Base(num), D1(num), D2(num) { }
	MI(const MI &orig) : Base(orig), D1(orig), D2(orig) { }
};

class Final : public MI, public Class
{
public:
	Final() { }
	Final(int num) : Base(num), MI(num) { }
	Final(const Final &orig) : Base(orig), MI(orig) { }
};
