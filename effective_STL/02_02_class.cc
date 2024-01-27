#include <list>

using std::list;

class Customer {};

class CustomerList
{
private:
	typedef list<Customer> CustomerContainer;
	typedef CustomerContainer::iterator CCIterator;

	CustomerContainer customers;

public:
//
};
