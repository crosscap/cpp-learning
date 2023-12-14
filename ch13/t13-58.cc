#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Foo
{
	public:
	Foo sorted() &&;
	Foo sorted() const &;

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	return Foo(*this).sorted();
}