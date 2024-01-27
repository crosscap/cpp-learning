#include <typeinfo>
#include <iostream>
#include <string>

#include "Derived.h"
#include "Sales_data.h"

using std::cout;
using std::endl;

int main()
{
	int arr[10];
	Derived d;
	Base *p = &d;

	cout << typeid(42).name() << ", "
		 << typeid(arr).name() << ", "
		 << typeid(Sales_data).name() << ", "
		 << typeid(std::string).name() << ", "
		 << typeid(p).name() << ", "
		 << typeid(*p).name() << std::endl;

	return 0;
}
