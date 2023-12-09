#include <iostream>
#include <vector>

struct X
{
	X() {std::cout << "X()" << std::endl;}
	X(const X&){std::cout << "X(const X&)" << std::endl;}
	~X() {std::cout << "~X()" << std::endl;}
	X &operator=(const X &rhs) {std::cout << "X &operator=" << std::endl; return *this;}
};

void function_copy(X x) {}
void function_r(X &x) {}

int main()
{
	std::cout << "begin" <<std::endl;
	X x;
	std::cout <<std::endl;

	std::cout << "copy" <<std::endl;
	function_copy(x);
	std::cout <<std::endl;

	std::cout << "reference" <<std::endl;
	function_r(x);
	std::cout <<std::endl;

	std::cout << "new" <<std::endl;
	X *px = new X;
	std::cout <<std::endl;

	std::cout << "vector" <<std::endl;
	std::vector<X> vx;
	vx.push_back(x);
	std::cout <<std::endl;

	std::cout << "delete" <<std::endl;
	delete px;
	std::cout <<std::endl;

	std::cout << "x2" <<std::endl;
	X x2 = x;
	std::cout <<std::endl;

	std::cout << "x3" <<std::endl;
	X x3(x);
	std::cout <<std::endl;

	return 0;
}