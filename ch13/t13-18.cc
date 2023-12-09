#include <string>

using std::string;

class Employee
{
public:
	Employee() : id(counter++) {}
	Employee(const string &s) :name(s), id(counter++) {}
	Employee(const Employee &orig) : name(orig.name), id(counter++) {}

	Employee &operator=(const Employee &rhs);

	string get_name() const {return name;}
	int get_id() const {return id;}

private:
	string name;
	int id;
	static int counter;
};

int Employee::counter = 0;

Employee &Employee::operator=(const Employee &rhs)
{
	name = rhs.name;
	id = counter++;

	return *this;
}
